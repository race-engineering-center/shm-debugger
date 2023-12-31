#include <fstream>
#include <iostream>
#include <thread>

#include <boost/program_options.hpp>

#include "application.h"
#include "emulator_iracing.h"
#include "data_iracing.h"
#include "emulator_acc.h"
#include "data_acc.h"
#include "loader.h"

int main(int argc, char* argv[]) {
    namespace po = boost::program_options;
    std::string inputFileName;

    po::options_description desc("Allowed options");

    // clang-format off
    desc.add_options()
        ("help", "Produce help message")
        ("input-file", po::value<std::string>(&inputFileName)->required(), "Input file name");
    // clang-format on

    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }
        po::notify(vm);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    try {
        std::map<std::array<char, 4>, std::shared_ptr<Emulator>> emulators;
        emulators[ACC::id()] = std::make_shared<ACC::Emulator>();
        emulators[iRacing::id()] = std::make_shared<iRacing::Emulator>();

        std::ifstream stream(inputFileName, std::ios::binary);
        Loader loader(stream);

        auto emulator = emulators.at(loader.getId());
        std::cout << "Using emulator: ";
        for (char c : loader.getId()) {
            std::cout << c;
        }
        std::cout << std::endl;
        emulator->initialize();

        Application app;
        std::cout << "Frames per second: " << loader.getFps() << std::endl;
        std::cout << "Emulator started" << std::endl;

        app.run(
            [&emulator, &loader]() -> bool {
                auto data = loader.load();
                if (data.empty()) {
                    std::cout << "Emulator reached end of file" << std::endl;
                    return true;
                }

                emulator->update(data);
                return false;
            },
            loader.getFps());
    } catch (std::exception& ex) {
        std::cout << "An error occurred: " << ex.what() << std::endl;
    }

    std::cout << "Emulator thread stopped." << std::endl;
    std::cout << "You can now close this window." << std::endl;

    return 0;
}

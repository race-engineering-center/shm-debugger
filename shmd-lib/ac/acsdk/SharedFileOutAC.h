#ifndef SHAREDFILEOUT_H
#define SHAREDFILEOUT_H

typedef int AC_STATUS;

#define AC_OFF 0
#define AC_REPLAY 1
#define AC_LIVE 2
#define AC_PAUSE 3

typedef int AC_SESSION_TYPE;

#define AC_UNKNOWN -1
#define AC_PRACTICE 0
#define AC_QUALIFY 1
#define AC_RACE 2
#define AC_HOTLAP 3
#define AC_TIME_ATTACK 4
#define AC_DRIFT 5
#define AC_DRAG 6

typedef int AC_FLAG_TYPE;

#define AC_NO_FLAG 0
#define AC_BLUE_FLAG 1
#define AC_YELLOW_FLAG 2
#define AC_BLACK_FLAG 3
#define AC_WHITE_FLAG 4
#define AC_CHECKERED_FLAG 5
#define AC_PENALTY_FLAG 6

#pragma pack(push, 1)

struct SPageFilePhysicsAC {
    int packetId = 0;
    float gas = 0;
    float brake = 0;
    float fuel = 0;
    int gear = 0;
    int rpms = 0;
    float steerAngle = 0;
    float speedKmh = 0;
    float velocity[3];
    float accG[3];
    float wheelSlip[4];
    float wheelLoad[4];
    float wheelsPressure[4];
    float wheelAngularSpeed[4];
    float tyreWear[4];
    float tyreDirtyLevel[4];
    float tyreCoreTemperature[4];
    float camberRAD[4];
    float suspensionTravel[4];
    float drs = 0;
    float tc = 0;
    float heading = 0;
    float pitch = 0;
    float roll = 0;
    float cgHeight;
    float carDamage[5];
    int numberOfTyresOut = 0;
    int pitLimiterOn = 0;
    float abs = 0;
    float kersCharge = 0;
    float kersInput = 0;
    int autoShifterOn = 0;
    float rideHeight[2];
    float turboBoost = 0;
    float ballast = 0;
    float airDensity = 0;
    float airTemp = 0;
    float roadTemp = 0;
    float localAngularVel[3];
    float finalFF = 0;
    float performanceMeter = 0;

    int engineBrake = 0;
    int ersRecoveryLevel = 0;
    int ersPowerLevel = 0;
    int ersHeatCharging = 0;
    int ersIsCharging = 0;
    float kersCurrentKJ = 0;

    int drsAvailable = 0;
    int drsEnabled = 0;

    float brakeTemp[4];

    float clutch;

    float tyreOTemperature[4];
    float tyreMTemperature[4];
    float tyreITemperature[4];

    int isAIControlled;

    float tyreContactPoint[4][3]; //[Front Left, Front Right, Rear Left, Rear Right][x, y, z]
    float tyreContactNormal[4][3];
    float tyreContactHeading[4][3];
    float brakeBias;
};

struct SPageFileGraphicAC {
    int packetId = 0;
    AC_STATUS status = AC_OFF;
    AC_SESSION_TYPE session = AC_PRACTICE;
    wchar_t currentTime[15];
    wchar_t lastTime[15];
    wchar_t bestTime[15];
    wchar_t split[15];
    int completedLaps = 0;
    int position = 0;
    int iCurrentTime = 0;
    int iLastTime = 0;
    int iBestTime = 0;
    float sessionTimeLeft = 0;
    float distanceTraveled = 0;
    int isInPit = 0;
    int currentSectorIndex = 0;
    int lastSectorTime = 0;
    int numberOfLaps = 0;
    wchar_t tyreCompound[33];

    float replayTimeMultiplier = 0;
    float normalizedCarPosition = 0;
    float carCoordinates[3];
    float penaltyTime = 0;
    AC_FLAG_TYPE flag = AC_NO_FLAG;
    int idealLineOn = 0;
    int isInPitLane = 0;

    float surfaceGrip = 0;
};

struct SPageFileStaticAC {
    wchar_t smVersion[15];
    wchar_t acVersion[15];

    // session static info
    int numberOfSessions = 0;
    int numCars = 0;
    wchar_t carModel[33];
    wchar_t track[33];
    wchar_t playerName[33];
    wchar_t playerSurname[33];
    wchar_t playerNick[33];
    int sectorCount = 0;

    // car static info
    float maxTorque = 0;
    float maxPower = 0;
    int maxRpm = 0;
    float maxFuel = 0;
    float suspensionMaxTravel[4];
    float tyreRadius[4];
    float maxTurboBoost = 0;

    float deprecated_1 = -273;
    float deprecated_2 = -273;

    int penaltiesEnabled = 0;

    float aidFuelRate = 0;
    float aidTireRate = 0;
    float aidMechanicalDamage = 0;
    int aidAllowTyreBlankets = 0;
    float aidStability = 0;
    int aidAutoClutch = 0;
    int aidAutoBlip = 0;

    int hasDRS = 0;
    int hasERS = 0;
    int hasKERS = 0;
    float kersMaxJ = 0;
    int engineBrakeSettingsCount = 0;
    int ersPowerControllerCount = 0;

    float trackSplineLength = 0;
    wchar_t trackConfiguration[33];
};

#pragma pack(pop)

#endif

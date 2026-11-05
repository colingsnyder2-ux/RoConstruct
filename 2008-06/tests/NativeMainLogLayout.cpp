#include "CRobloxApp.h"
#include <cstddef>

typedef char LogManagerSize[sizeof(LogManager) == 0x28 ? 1 : -1];
typedef char MainLogManagerSize[sizeof(MainLogManager) == 0x4c ? 1 : -1];
typedef char ThreadLogManagerSize[sizeof(ThreadLogManager) == 0x28 ? 1 : -1];
typedef char AppLogManagerOffset[offsetof(CRobloxApp, logManager) == 0xa4 ? 1 : -1];
typedef char AppVersionOffset[offsetof(CRobloxApp, version) == 0xf0 ? 1 : -1];

RBX::ILogProvider* asProvider(MainLogManager* manager) { return manager; }
LogManager* asLogManager(MainLogManager* manager) { return manager; }

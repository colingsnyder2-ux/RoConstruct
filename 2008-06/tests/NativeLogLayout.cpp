#include <fstream>
#include <string>
#include <cstddef>
#define private public
#include "util/Log.h"
#undef private

typedef char LogNameOffset[(offsetof(RBX::Log, name) == 0x04) ? 1 : -1];
typedef char LogSeverityOffset[(offsetof(RBX::Log, worstSeverity) == 0x20) ? 1 : -1];
typedef char LogFileOffset[(offsetof(RBX::Log, logFile) == 0x24) ? 1 : -1];
typedef char LogStreamOffset[(offsetof(RBX::Log, stream) == 0x40) ? 1 : -1];

#include "../native-classes/CRobloxView.cpp"
#include "../native-headers/CRobloxView.h"
#include <cstddef>

// Layout claims from RTTI base offsets and constructor 00459eb0.
typedef char WindowSize[sizeof(CRobloxWnd) == 0xc0 ? 1 : -1];
typedef char ReflectorSize[sizeof(CReflectorWnd) == 0x58 ? 1 : -1];
typedef char MenuSize[sizeof(CMenu) == 8 ? 1 : -1];
typedef char ViewSize[sizeof(CRobloxView) == 0x1f0 ? 1 : -1];
typedef char WindowOffset[offsetof(CRobloxView, window) == 0xb0 ? 1 : -1];
typedef char MenuOffset[offsetof(CRobloxView, popupMenu) == 0x178 ? 1 : -1];
typedef char ReflectorOffset[offsetof(CRobloxView, reflector) == 0x180 ? 1 : -1];
typedef char TailOffset[offsetof(CRobloxView, slot_1d8) == 0x1d8 ? 1 : -1];


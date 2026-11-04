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


// Owner copies in 0045f7b0 and release in 0045fbe0 prove this member.
typedef char WindowDataModelOffset[offsetof(CRobloxWnd, dataModel) == 0x70 ? 1 : -1];
typedef char WindowDataModelOwnerSize[sizeof(((CRobloxWnd*)0)->dataModel) == 8 ? 1 : -1];
typedef char WindowRunServiceOffset[offsetof(CRobloxWnd, runService) == 0x78 ? 1 : -1];

typedef char WindowWorkspaceOffset[offsetof(CRobloxWnd, workspace) == 0x6c ? 1 : -1];
typedef char WindowWorkspaceOwnerSize[sizeof(((CRobloxWnd*)0)->workspace) == 4 ? 1 : -1];

typedef char WindowUserInputOffset[offsetof(CRobloxWnd, userInput) == 0x84 ? 1 : -1];
typedef char WindowUserInputOwnerSize[sizeof(((CRobloxWnd*)0)->userInput) == 4 ? 1 : -1];

typedef char WindowContextOffset[offsetof(CRobloxWnd, gWindow) == 0xa4 ? 1 : -1];
typedef char WindowAdornOffset[offsetof(CRobloxWnd, adorn) == 0xb4 ? 1 : -1];
typedef char WindowAdornOwnerSize[sizeof(((CRobloxWnd*)0)->adorn) == 4 ? 1 : -1];

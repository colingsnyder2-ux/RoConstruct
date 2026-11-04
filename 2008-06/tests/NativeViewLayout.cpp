#include "../native-classes/CRobloxView.cpp"
#include "../native-headers/CRobloxView.h"
#include <cstddef>
#include <GLG3D/RenderDevice.h>

// Layout claims from RTTI base offsets and constructor 00459eb0.
typedef char WindowSize[sizeof(CRobloxWnd) == 0xc0 ? 1 : -1];
typedef char ReflectorSize[sizeof(CMultiPlayerPane) == 0x58 ? 1 : -1];
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

typedef char WindowThrottleOffset[offsetof(CRobloxWnd, pendingThrottle) == 0x90 ? 1 : -1];
typedef char WindowThrottleSize[sizeof(((CRobloxWnd*)0)->pendingThrottle) == 8 ? 1 : -1];

typedef char WindowRenderStatsOffset[offsetof(CRobloxWnd, renderStats) == 0x64 ? 1 : -1];
typedef char WindowRenderStatsOwnerSize[sizeof(((CRobloxWnd*)0)->renderStats) == 8 ? 1 : -1];
typedef char WindowProfilerOffset[offsetof(CRobloxWnd, profiler) == 0x98 ? 1 : -1];
typedef char WindowVisualEngineOffset[offsetof(CRobloxWnd, visualEngine) == 0xb8 ? 1 : -1];

typedef char WindowThreadIdOffset[offsetof(CRobloxWnd, windowThreadId) == 0xa0 ? 1 : -1];
typedef char WindowRenderDeviceOffset[offsetof(CRobloxWnd, renderDevice) == 0xac ? 1 : -1];
typedef char WindowViewOwnerOffset[offsetof(CRobloxWnd, view) == 0xb0 ? 1 : -1];
typedef char RenderDeviceSize[sizeof(G3D::RenderDevice) == 0x8b0 ? 1 : -1];

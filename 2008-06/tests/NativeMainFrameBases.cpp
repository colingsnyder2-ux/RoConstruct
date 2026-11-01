#include "../native-headers/CMainFrame.h"
#include <stddef.h>
CMainFrameBases* nativeMainFrameBases;
typedef char checkWindowPos[(sizeof(CXTWindowPos) == 0x2c) ? 1 : -1];
typedef char checkDockingManager[(sizeof(CXTPDockingPaneManager) == 0x14c) ? 1 : -1];
typedef char checkTabClient[(sizeof(CXTPTabClientWnd) == 0x124) ? 1 : -1];
typedef char checkThemeManager[(sizeof(CXTThemeManager) == 0x2c) ? 1 : -1];
typedef char checkStatusBar[(sizeof(CXTPStatusBar) == 0xd4) ? 1 : -1];
typedef char checkDockingOffset[(offsetof(CMainFrameXtpComponents, dockingPanes) == 0x2c) ? 1 : -1];
typedef char checkTabsOffset[(offsetof(CMainFrameXtpComponents, tabClient) == 0x178) ? 1 : -1];
typedef char checkComponentsSize[(sizeof(CMainFrameXtpComponents) == 0x29c) ? 1 : -1];
typedef char checkPanePointersSize[(sizeof(CMainFramePanePointers) == 0xc) ? 1 : -1];
typedef char checkPropertyPointer[(offsetof(CMainFramePanePointers, propertyGrid) == 4) ? 1 : -1];
typedef char checkCaptionPointer[(offsetof(CMainFramePanePointers, selectionCaption) == 8) ? 1 : -1];

typedef char checkFullSize[(sizeof(CMainFrame) == 0x4b4) ? 1 : -1];
typedef char checkKeepAlive[(offsetof(CMainFrame, keepAlive) == 0xf4) ? 1 : -1];
typedef char checkMonitor[(offsetof(CMainFrame, monitor) == 0xfc) ? 1 : -1];
typedef char checkText[(offsetof(CMainFrame, text) == 0x108) ? 1 : -1];
typedef char checkComponents[(offsetof(CMainFrame, windowPosition) == 0x10c) ? 1 : -1];
typedef char checkPanePointers[(offsetof(CMainFrame, splitter) == 0x3a8) ? 1 : -1];
typedef char checkTheme[(offsetof(CMainFrame, theme) == 0x3b4) ? 1 : -1];
typedef char checkStatus[(offsetof(CMainFrame, status) == 0x3e0) ? 1 : -1];
typedef char checkDockingMember[(offsetof(CMainFrame, dockingPanes) == 0x138) ? 1 : -1];
typedef char checkTabMember[(offsetof(CMainFrame, tabClient) == 0x284) ? 1 : -1];
typedef char checkPropertyMember[(offsetof(CMainFrame, propertyGrid) == 0x3ac) ? 1 : -1];
typedef char checkCaptionMember[(offsetof(CMainFrame, selectionCaption) == 0x3b0) ? 1 : -1];

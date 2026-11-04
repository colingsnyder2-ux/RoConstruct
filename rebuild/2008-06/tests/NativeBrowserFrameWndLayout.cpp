#include <stddef.h>
#include "CBrowserFrameWnd.h"
// CBrowserFrameWnd: CRuntimeClass 00811e90 size 0xec and CreateObject 00433280 operator new(0xec). The class adds no
// members: its deleting destructor 00433240 only stores a vptr and calls the site-base destructor 00432fd0, which
// releases the command bars pointer at +0xe8 (CXTPCommandBarsSiteBase<CFrameWnd>, declared private in the XTP header).
typedef char FrameWndSize[sizeof(CFrameWnd) == 0xe8 ? 1 : -1];
typedef char SiteBaseSize[sizeof(CXTPCommandBarsSiteBase<CFrameWnd>) == 0xec ? 1 : -1];
typedef char XtpFrameWndSize[sizeof(CXTPFrameWnd) == 0xec ? 1 : -1];
typedef char BrowserFrameWndSize[sizeof(CBrowserFrameWnd) == 0xec ? 1 : -1];
// CFrameWnd members the OnCreate body (00433130) reads: m_hWnd +0x20 (CWnd), and the frame's accelerator table
// m_hAccelTable +0x60 (LoadFrame 004331c0 clears it when the command bars own the accelerators).
typedef char HwndOffset[offsetof(CBrowserFrameWnd, m_hWnd) == 0x20 ? 1 : -1];
typedef char AccelOffset[offsetof(CFrameWnd, m_hAccelTable) == 0x60 ? 1 : -1];

#include <stddef.h>
#include "CChildFrame.h"
// CRuntimeClass 0080e468 / 0080e484 give size 0xf0 for both frames, and both CreateObject functions
// (00412c90 / 00412cf0) call operator new(0xf0) and then CMDIChildWnd::CMDIChildWnd, storing only the vptr.
typedef char ChildFrameSize[sizeof(CChildFrame) == 0xf0 ? 1 : -1];
typedef char RbxChildFrameSize[sizeof(CRbxChildFrame) == 0xf0 ? 1 : -1];
typedef char MDIChildWndSize[sizeof(CMDIChildWnd) == 0xf0 ? 1 : -1];
typedef char FrameWndSize[sizeof(CFrameWnd) == 0xe8 ? 1 : -1];
// OnCreate 00412b90 clears +0xe8 (CMDIChildWnd::m_hMenuShared, the first CMDIChildWnd member).
struct ChildFrameMembers : CChildFrame {
    static void check() { typedef char MenuShared[offsetof(ChildFrameMembers, m_hMenuShared) == 0xe8 ? 1 : -1]; }
};
// PreCreateWindow 00412b00 writes CREATESTRUCT cy/cx/y/x/style at +0x10/+0x14/+0x18/+0x1c/+0x20.
typedef char CreateCy[offsetof(CREATESTRUCT, cy) == 0x10 ? 1 : -1];
typedef char CreateX[offsetof(CREATESTRUCT, x) == 0x1c ? 1 : -1];
typedef char CreateStyle[offsetof(CREATESTRUCT, style) == 0x20 ? 1 : -1];
// OnGetMinMaxInfo 00412e60 adjusts ptMaxSize (+8) and ptMaxTrackSize (+0x20).
typedef char MaxSize[offsetof(MINMAXINFO, ptMaxSize) == 8 ? 1 : -1];
typedef char MaxTrackSize[offsetof(MINMAXINFO, ptMaxTrackSize) == 0x20 ? 1 : -1];

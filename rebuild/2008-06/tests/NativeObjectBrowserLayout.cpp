#include <stddef.h>
#include "CObjectBrowser.h"
// Size from CRuntimeClass 00812520 and CreateObject 00433950 (operator new(0x288)); CView (mfc90) is 0x58.
// Member offsets from the constructor 00433420 / destructor 00433480 (CXTSplitterWnd ctor/dtor on +0x58 and +0x170)
// and OnSize 004339d0 (m_hWnd reads at +0x78 = +0x58 + 0x20 and +0x190 = +0x170 + 0x20).
int viewSize() { return sizeof(CView); }                                     // 0x58
int splitterSize() { return sizeof(CXTSplitterWnd); }                        // 0x118
int objectBrowserSize() { return sizeof(CObjectBrowser); }                   // 0x288
int classSplitterOffset() { return offsetof(CObjectBrowser, classSplitter); }  // 0x58
int memberSplitterOffset() { return offsetof(CObjectBrowser, memberSplitter); }  // 0x170
int splitterWindowOffset() { return offsetof(CXTSplitterWnd, m_hWnd); }       // 0x20

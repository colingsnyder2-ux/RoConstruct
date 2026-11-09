#include <stddef.h>
#include "CSecureHtmlView.h"
// Size from CRuntimeClass 0081b840 (0xf8) and CWebToolbox's inlined CSecureHtmlView constructor in
// CreateObject 0046a850 (operator new(0x100) for the derived class, base part ends at 0xf8).
// CHtmlView (mfc90) is 0xf4; the constructor 00465a60 clears byte +0xf4 after CHtmlView::CHtmlView,
// OnAmbientProperty 00465a90 tests it; the destructor 00465a80 only resets the vtable (no members to destroy).
typedef char HtmlViewSize[sizeof(CHtmlView) == 0xf4 ? 1 : -1];
typedef char SecureHtmlViewSize[sizeof(CSecureHtmlView) == 0xf8 ? 1 : -1];
typedef char SecureHtmlViewFlag[offsetof(CSecureHtmlView, flag_f4) == 0xf4 ? 1 : -1];
typedef char FlagSize[sizeof(bool) == 1 ? 1 : -1];

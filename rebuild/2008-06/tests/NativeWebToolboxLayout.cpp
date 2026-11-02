#include <stddef.h>
#include "CWebToolbox.h"
// Size from CRuntimeClass 0081c4a8 (0x100) and the operator new(0x100) in CreateObject 0046a850.
// CSecureHtmlView size from CRuntimeClass 0081b840 (0xf8); its constructor 00465a60 writes byte +0xf4.
// +0xf8 from SetFocus loads in 0046a640/0046a660/0046a6a0/0046a6d0/0046a6f0/0046a7c0/0046a8e0;
// +0xfc from the CreateObject null store, the deleting destructor 0046a7e0 Release and OnGetExternal 0046a8e0.
typedef char HtmlViewSize[sizeof(CHtmlView) == 0xf4 ? 1 : -1];
typedef char SecureHtmlViewSize[sizeof(CSecureHtmlView) == 0xf8 ? 1 : -1];
typedef char SecureHtmlViewFlag[offsetof(CSecureHtmlView, flag_f4) == 0xf4 ? 1 : -1];
typedef char WebToolboxSize[sizeof(CWebToolbox) == 0x100 ? 1 : -1];
typedef char WebToolboxField[offsetof(CWebToolbox, field_f8) == 0xf8 ? 1 : -1];
typedef char WebToolboxExternal[offsetof(CWebToolbox, external) == 0xfc ? 1 : -1];
typedef char ComPtrSize[sizeof(CComPtr<IDispatch>) == 4 ? 1 : -1];

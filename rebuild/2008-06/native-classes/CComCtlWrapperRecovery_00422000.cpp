// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Recovered CComCtlWrapper GetProcAddress_* members (cached comctl32 proc addresses).
#include <afxwin.h>

int keep_CComCtlWrapperRecovery_00422000() {
    CComCtlWrapper w;
    CComCtlWrapper::ImageList_EndDrag_Type (CComCtlWrapper::*p0)() = &CComCtlWrapper::GetProcAddress_ImageList_EndDrag;
    CComCtlWrapper::ImageList_DragEnter_Type (CComCtlWrapper::*p1)() = &CComCtlWrapper::GetProcAddress_ImageList_DragEnter;
    CComCtlWrapper::ImageList_DragLeave_Type (CComCtlWrapper::*p2)() = &CComCtlWrapper::GetProcAddress_ImageList_DragLeave;
    CComCtlWrapper::ImageList_DragMove_Type (CComCtlWrapper::*p3)() = &CComCtlWrapper::GetProcAddress_ImageList_DragMove;
    CComCtlWrapper::ImageList_DragShowNolock_Type (CComCtlWrapper::*p4)() = &CComCtlWrapper::GetProcAddress_ImageList_DragShowNolock;
    (w.*p0)();
    (w.*p1)();
    (w.*p2)();
    (w.*p3)();
    (w.*p4)();
    return 0;
}

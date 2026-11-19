// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Recovered CComCtlWrapper GetProcAddress_* members (cached comctl32 proc addresses).
// The header already declares and defines these members, so no out-of-line bodies are redefined here.
// 00421ed0 = GetProcAddress_ImageList_BeginDrag
// 00422000 = GetProcAddress_ImageList_EndDrag (sub_00422000)
// 004220d0 = GetProcAddress_ImageList_DragEnter (sub_004220d0)
// 004221f0 = GetProcAddress_ImageList_DragLeave (sub_004221f0)
// 00422310 = GetProcAddress_ImageList_DragMove (sub_00422310)
// 00422430 = GetProcAddress_ImageList_DragShowNolock (sub_00422430)
#include <afxwin.h>

int keep_CComCtlWrapperRecovery_00422000() {
    CComCtlWrapper w;
    CComCtlWrapper::ImageList_BeginDrag_Type (CComCtlWrapper::*p5)() = &CComCtlWrapper::GetProcAddress_ImageList_BeginDrag;
    CComCtlWrapper::ImageList_EndDrag_Type (CComCtlWrapper::*p0)() = &CComCtlWrapper::GetProcAddress_ImageList_EndDrag;
    CComCtlWrapper::ImageList_DragEnter_Type (CComCtlWrapper::*p1)() = &CComCtlWrapper::GetProcAddress_ImageList_DragEnter;
    CComCtlWrapper::ImageList_DragLeave_Type (CComCtlWrapper::*p2)() = &CComCtlWrapper::GetProcAddress_ImageList_DragLeave;
    CComCtlWrapper::ImageList_DragMove_Type (CComCtlWrapper::*p3)() = &CComCtlWrapper::GetProcAddress_ImageList_DragMove;
    CComCtlWrapper::ImageList_DragShowNolock_Type (CComCtlWrapper::*p4)() = &CComCtlWrapper::GetProcAddress_ImageList_DragShowNolock;
    (w.*p5)();
    (w.*p0)();
    (w.*p1)();
    (w.*p2)();
    (w.*p3)();
    (w.*p4)();
    return 0;
}

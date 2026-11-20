// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

struct CComCtlWrapperLayout {
    char padding[0x9c];
    FARPROC m_pfnImageList_GetImageInfo;
};

void __fastcall sub_006ba510(CComCtlWrapperLayout* self, void* /*edx*/, FARPROC* result)
{
    if (!self->m_pfnImageList_GetImageInfo)
        self->m_pfnImageList_GetImageInfo = ::GetProcAddress(::GetModuleHandleA("comctl32.dll"), "ImageList_GetImageInfo");
    *result = self->m_pfnImageList_GetImageInfo;
}
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <objbase.h>

// INFERRED: globals at 0x97db4c (result) / 0x97db50 (initialized flag); GUIDs at 0x81e448 / 0x81e458.
extern void* g_cachedResult;
extern bool g_cachedInit;
extern const CLSID g_clsid;
extern const IID g_iid;

// INFERRED: COM interface, only vtable slots 0x48, 0x5c and Release(2) are used.
struct IUnknownLike {
    void** vtbl;
};

extern "C" void* fn_00678510()
{
    if (!g_cachedInit) {
        IUnknownLike* obj = 0;
        void* out = 0;
        CoInitialize(0);
        if (CoCreateInstance(g_clsid, 0, CLSCTX_INPROC_SERVER, g_iid, (void**)&obj) >= 0) {
            ((HRESULT (__stdcall*)(IUnknownLike*, int))obj->vtbl[0x48 / 4])(obj, 0);
            DWORD flags = 0x10004000;
            if (((HRESULT (__stdcall*)(IUnknownLike*, DWORD*, void**, void**))obj->vtbl[0x5c / 4])(obj, &flags, &g_cachedResult, &out) < 0) {
                g_cachedResult = 0;
                out = 0;
            }
            ((ULONG (__stdcall*)(IUnknownLike*))obj->vtbl[8 / 4])(obj);
        }
        CoUninitialize();
        g_cachedInit = true;
    }
    return g_cachedResult;
}

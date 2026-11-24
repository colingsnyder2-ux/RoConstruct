// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct _GUID;

namespace ATL {
class CComTypeInfoHolder {
public:
    long GetIDsOfNames(const _GUID& riid, wchar_t** rgszNames, unsigned int cNames,
                       unsigned long lcid, long* rgdispid);
};
}

// INFERRED: unknown global CComTypeInfoHolder instance at 0x00928bd8
extern "C" ATL::CComTypeInfoHolder g_00928bd8;

// INFERRED: first argument is unused; the remaining five are forwarded to
// the static CComTypeInfoHolder instance.
extern "C" long __stdcall fn_00408150(void* unused,
                                      const _GUID* riid,
                                      wchar_t** rgszNames,
                                      unsigned int cNames,
                                      unsigned long lcid,
                                      long* rgdispid)
{
    return g_00928bd8.GetIDsOfNames(*riid, rgszNames, cNames, lcid, rgdispid);
}

// from server: 61% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned int UINT;
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef const char* LPCSTR;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long HRESULT;
typedef const wchar_t* LPCWSTR;
typedef wchar_t* BSTR;
typedef void* PVOID;

struct VARIANT {
    WORD vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    union {
        BSTR bstrVal;
        PVOID byref;
    } data;
};

extern "C" HRESULT __stdcall VariantClear(VARIANT* pvarg);
extern "C" UINT __stdcall SysStringByteLen(BSTR bstr);
extern "C" BSTR __stdcall SysAllocStringByteLen(LPCSTR psz, UINT len);
extern "C" void __cdecl func_004041b0();

struct CRobloxPlayerDlg {
    VARIANT* func_0048d070(BSTR* pbstr);
};

VARIANT* CRobloxPlayerDlg::func_0048d070(BSTR* pbstr)
{
    VARIANT* thisVar = reinterpret_cast<VARIANT*>(this);
    VariantClear(thisVar);
    thisVar->vt = 8;
    BSTR bstr = *pbstr;
    if (bstr) {
        UINT len = SysStringByteLen(bstr);
        BSTR newBstr = SysAllocStringByteLen(reinterpret_cast<LPCSTR>(bstr), len);
        thisVar->data.bstrVal = newBstr;
        if (!newBstr) {
            if (*pbstr) {
                thisVar->vt = 10;
                thisVar->data.byref = reinterpret_cast<PVOID>(0x8007000e);
                func_004041b0();
            }
        }
    } else {
        thisVar->data.bstrVal = 0;
    }
    return thisVar;
}

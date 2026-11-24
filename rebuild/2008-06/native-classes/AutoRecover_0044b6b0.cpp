// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: ATL structs are declared locally (layout taken from the disassembly offsets);
// callees use the fn_<addr> convention.

struct FnGuid {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
};

struct FnCatMapEntry;

struct FnObjMapEntry {
    const FnGuid* pclsid;                          // +0
    long (__stdcall *pfnUpdateRegistry)(int);      // +4
    void* pad0[5];                                 // +8..+0x1b
    const FnCatMapEntry* (__stdcall *pfnGetCategoryMap)(); // +0x1c
};

struct FnComModule {
    unsigned int cbSize;                           // +0
    void* m_hInstTypeLib;                          // +4
    FnObjMapEntry** m_ppAutoObjMapFirst;           // +8
    FnObjMapEntry** m_ppAutoObjMapLast;            // +0xc
};

extern "C" int __cdecl fn_0042ad40(const FnGuid* a, const FnGuid* b);
extern "C" long __stdcall fn_0044b1b0(const FnGuid* clsid, const FnCatMapEntry* map, int bRegister);
extern "C" long __stdcall fn_0044b590(void* hInst, const wchar_t* lpszIndex);

extern "C" long __stdcall fn_0044b6b0(FnComModule* pComModule, int bRegTypeLib, const FnGuid* pCLSID)
{
    if (pComModule == 0)
        return (long)0x80070057L; // E_INVALIDARG

    long hr = 0;
    for (FnObjMapEntry** ppEntry = pComModule->m_ppAutoObjMapFirst;
         ppEntry < pComModule->m_ppAutoObjMapLast; ppEntry++)
    {
        if (*ppEntry != 0)
        {
            FnObjMapEntry* pEntry = *ppEntry;
            if (pCLSID != 0)
            {
                if (!fn_0042ad40(pCLSID, pEntry->pclsid))
                    continue;
            }
            hr = pEntry->pfnUpdateRegistry(1);
            if (hr < 0)
                break;
            hr = fn_0044b1b0(pEntry->pclsid, pEntry->pfnGetCategoryMap(), 1);
            if (hr < 0)
                break;
        }
    }
    if (hr >= 0 && bRegTypeLib)
        hr = fn_0044b590(pComModule->m_hInstTypeLib, 0);
    return hr;
}

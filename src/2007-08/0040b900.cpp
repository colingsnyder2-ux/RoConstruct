// from server: 100% by colin
// roc 2007-08 0040b900  unit: VCBrowserViewExternal::?$CComContainedObject  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b900
//
// 0040b900  8b442404             mov eax, dword ptr [esp + 4]
// 0040b904  8b4018               mov eax, dword ptr [eax + 0x18]
// 0040b907  8b08                 mov ecx, dword ptr [eax]
// 0040b909  89442404             mov dword ptr [esp + 4], eax
// 0040b90d  8b5104               mov edx, dword ptr [ecx + 4]
// 0040b910  ffe2                 jmp edx
// copied from an identical function in another client (function ?AddRef@Contained@@QAGKXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct IUnknown {
    virtual long __stdcall QueryInterface(const void* iid, void** object) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Contained {
    char padding[24];
    IUnknown* outer;
    unsigned long __stdcall AddRef();
};

unsigned long __stdcall Contained::AddRef()
{
    return outer->AddRef();
}
// from server: 100% by colin
// roc 2007-03 0040cdf0  unit: seg_00400000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040cdf0
//
// 0040cdf0  8b442404             mov eax, dword ptr [esp + 4]
// 0040cdf4  8b4018               mov eax, dword ptr [eax + 0x18]
// 0040cdf7  8b08                 mov ecx, dword ptr [eax]
// 0040cdf9  89442404             mov dword ptr [esp + 4], eax
// 0040cdfd  8b01                 mov eax, dword ptr [ecx]
// 0040cdff  ffe0                 jmp eax
// copied from an identical function in another client (function ?QueryInterface@CAppContained@@UAGJABUGUID@@PAPAX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct GUID { unsigned long Data1; unsigned short Data2, Data3; unsigned char Data4[8]; };

struct IUnknown {
    virtual long __stdcall QueryInterface(const GUID& iid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class CAppContained : public IUnknown {
public:
    char pad[0x14];
    IUnknown* m_pOuterUnknown;

    long __stdcall QueryInterface(const GUID& iid, void** ppvObject);
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
};

long __stdcall CAppContained::QueryInterface(const GUID& iid, void** ppvObject)
{
    return m_pOuterUnknown->QueryInterface(iid, ppvObject);
}
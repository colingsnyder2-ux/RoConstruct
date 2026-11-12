// from server: 86% by EspClaude
// from server: 58% by colin
// roc 2007-08 004094b0  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004094b0
//
// 004094b0  53                   push ebx
// 004094b1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004094b5  85db                 test ebx, ebx
// 004094b7  56                   push esi
// 004094b8  57                   push edi
// 004094b9  7405                 je 0x4094c0
// 004094bb  8d43ec               lea eax, [ebx - 0x14]
// 004094be  eb02                 jmp 0x4094c2
// 004094c0  33c0                 xor eax, eax
// 004094c2  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004094c6  85ff                 test edi, edi
// 004094c8  7464                 je 0x40952e
// 004094ca  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004094ce  85f6                 test esi, esi
// 004094d0  745c                 je 0x40952e
// 004094d2  8b4824               mov ecx, dword ptr [eax + 0x24]
// 004094d5  55                   push ebp
// 004094d6  8d542414             lea edx, [esp + 0x14]
// 004094da  52                   push edx
// 004094db  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004094df  83c024               add eax, 0x24
// 004094e2  52                   push edx
// 004094e3  50                   push eax
// 004094e4  8b01                 mov eax, dword ptr [ecx]
// 004094e6  ffd0                 call eax
// 004094e8  8be8                 mov ebp, eax
// 004094ea  85ed                 test ebp, ebp
// 004094ec  7c2b                 jl 0x409519
// 004094ee  8b442414             mov eax, dword ptr [esp + 0x14]
// 004094f2  8b08                 mov ecx, dword ptr [eax]
// 004094f4  8b5108               mov edx, dword ptr [ecx + 8]
// 004094f7  50                   push eax
// 004094f8  ffd2                 call edx
// 004094fa  8bcb                 mov ecx, ebx
// 004094fc  e80ffeffff           call 0x409310
// 00409501  85c0                 test eax, eax
// 00409503  c70701000000         mov dword ptr [edi], 1
// 00409509  7514                 jne 0x40951f
// 0040950b  8b4304               mov eax, dword ptr [ebx + 4]
// 0040950e  8906                 mov dword ptr [esi], eax
// 00409510  8bc5                 mov eax, ebp
// 00409512  5d                   pop ebp
// 00409513  5f                   pop edi
// 00409514  5e                   pop esi
// 00409515  5b                   pop ebx
// 00409516  c21000               ret 0x10
// 00409519  c70700000000         mov dword ptr [edi], 0
// 0040951f  8bc5                 mov eax, ebp
// 00409521  5d                   pop ebp
// 00409522  5f                   pop edi
// 00409523  c70600000000         mov dword ptr [esi], 0
// 00409529  5e                   pop esi
// 0040952a  5b                   pop ebx
// 0040952b  c21000               ret 0x10
// 0040952e  5f                   pop edi

struct IUnk
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct RobloxCtl;

struct IObjectSafetyRobloxImpl
{
    void* vtbl;
    unsigned long m_dwCurrentSafety;
    int IsSafetyDisabled();
    long __stdcall GetInterfaceSafetyOptions(const void* riid, unsigned long* pdwSupported, unsigned long* pdwEnabled);
};

struct RobloxCtlPad { char pad[0x14]; };
struct RobloxCtl : RobloxCtlPad, IObjectSafetyRobloxImpl
{
    char pad2[0x24 - 0x14 - sizeof(IObjectSafetyRobloxImpl)];
    void* unkVtbl;
    IUnk* GetUnknown() { return reinterpret_cast<IUnk*>(&unkVtbl); }
};

long __stdcall IObjectSafetyRobloxImpl::GetInterfaceSafetyOptions(const void* riid, unsigned long* pdwSupported, unsigned long* pdwEnabled)
{
    RobloxCtl* pT = static_cast<RobloxCtl*>(this);
    if (pdwSupported == 0 || pdwEnabled == 0)
        return (long)0x80004003;
    long hr;
    IUnk* pUnk;
    hr = pT->GetUnknown()->QueryInterface(riid, (void**)&pUnk);
    if (hr >= 0)
    {
        pUnk->Release();
        int disabled = IsSafetyDisabled();
        *pdwSupported = 1;
        if (disabled)
            *pdwEnabled = 0;
        else
            *pdwEnabled = m_dwCurrentSafety;
    }
    else
    {
        *pdwSupported = 0;
        *pdwEnabled = 0;
    }
    return hr;
}

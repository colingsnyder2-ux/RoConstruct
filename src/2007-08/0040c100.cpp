// from server: 100% by EspClaude
// from server: 94% by Intel
// roc 2007-08 0040c100  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c100
//
// 0040c100  56                   push esi
// 0040c101  8b742408             mov esi, dword ptr [esp + 8]
// 0040c105  834618ff             add dword ptr [esi + 0x18], -1
// 0040c109  57                   push edi
// 0040c10a  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0040c10d  7536                 jne 0x40c145
// 0040c10f  85f6                 test esi, esi
// 0040c111  7432                 je 0x40c145
// 0040c113  8d4e08               lea ecx, [esi + 8]
// 0040c116  c706c05b7800         mov dword ptr [esi], 0x785bc0
// 0040c11c  c74604a85b7800       mov dword ptr [esi + 4], 0x785ba8
// 0040c123  c701845b7800         mov dword ptr [ecx], 0x785b84
// 0040c129  c746145c5b7800       mov dword ptr [esi + 0x14], 0x785b5c
// 0040c130  c74618010000c0       mov dword ptr [esi + 0x18], 0xc0000001
// 0040c137  e8e4a90500           call 0x466b20
// 0040c13c  56                   push esi
// 0040c13d  e8203b2200           call 0x62fc62
// 0040c142  83c404               add esp, 4
// 0040c145  8bc7                 mov eax, edi
// 0040c147  5f                   pop edi
// 0040c148  5e                   pop esi
// 0040c149  c20400               ret 4
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// 2007-08 0040c100: CComObjectNoLock-style Release; layout from target stores
// (vptrs at 0,4,8,0x14; refcount at 0x18 in a non-polymorphic root base;
// -(LONG_MAX/2) = 0xC0000001; thiscall at this+8; operator delete).

struct Root { long m_dwRef; long InternalRelease() { return --m_dwRef; } };
struct A0 { virtual void f0(); };
struct A1 { virtual void f1(); };
struct A2 { virtual void f2(); char pad[8]; void Term(); };
struct A3 { virtual void f3(); };

struct VCBrowserViewExternal : Root, A0, A1, A2, A3 {
    ~VCBrowserViewExternal() {
        m_dwRef = (long)0xC0000001;
        A2::Term();
    }
    virtual unsigned long __stdcall Release();
};

unsigned long __stdcall VCBrowserViewExternal::Release() {
    unsigned long l = InternalRelease();
    if (l == 0)
        delete this;
    return l;
}

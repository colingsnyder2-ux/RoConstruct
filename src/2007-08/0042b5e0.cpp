// from server: 100% by EspClaude
// from server: 81% by colin
// roc 2007-08 0042b5e0  unit: VCLuaFunction::?$CComObjectNoLock  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042b5e0
//
// 0042b5e0  56                   push esi
// 0042b5e1  8b742408             mov esi, dword ptr [esp + 8]
// 0042b5e5  834608ff             add dword ptr [esi + 8], -1
// 0042b5e9  57                   push edi
// 0042b5ea  8b7e08               mov edi, dword ptr [esi + 8]
// 0042b5ed  7528                 jne 0x42b617
// 0042b5ef  85f6                 test esi, esi
// 0042b5f1  7424                 je 0x42b617
// 0042b5f3  8bce                 mov ecx, esi
// 0042b5f5  c70670a27800         mov dword ptr [esi], 0x78a270
// 0042b5fb  c7460448a27800       mov dword ptr [esi + 4], 0x78a248
// 0042b602  c74608010000c0       mov dword ptr [esi + 8], 0xc0000001
// 0042b609  e88287feff           call 0x413d90
// 0042b60e  56                   push esi
// 0042b60f  e84e462000           call 0x62fc62
// 0042b614  83c404               add esp, 4
// 0042b617  8bc7                 mov eax, edi
// 0042b619  5f                   pop edi
// 0042b61a  5e                   pop esi
// 0042b61b  c20400               ret 4
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

struct IA {
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct IB {
    virtual void __stdcall g() = 0;
};

struct VCLuaFunction : IA, IB {
    long m_dwRef;
    static unsigned long __stdcall Decrement(long* p) { return --(*p); }
    ~VCLuaFunction();
    unsigned long InternalRelease() { return Decrement(&m_dwRef); }
    void FinalRelease() {}
};

template <class Base>
struct CComObjectNoLock : Base {
    ~CComObjectNoLock()
    {
        this->m_dwRef = -(0x7fffffffL / 2);
        this->FinalRelease();
    }
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release()
    {
        unsigned long l = this->InternalRelease();
        if (l == 0)
            delete this;
        return l;
    }
    void __stdcall g();
};

template struct CComObjectNoLock<VCLuaFunction>;

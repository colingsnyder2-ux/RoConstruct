// from server: 94% by EspClaude
// from server: 82% by colin
// roc 2007-08 00402c50  unit: VCWorkspace::?$CComObject  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00402c50
//
// 00402c50  8b442404             mov eax, dword ptr [esp + 4]
// 00402c54  834030ff             add dword ptr [eax + 0x30], -1
// 00402c58  56                   push esi
// 00402c59  8b7030               mov esi, dword ptr [eax + 0x30]
// 00402c5c  7510                 jne 0x402c6e
// 00402c5e  85c0                 test eax, eax
// 00402c60  740c                 je 0x402c6e
// 00402c62  8d4820               lea ecx, [eax + 0x20]
// 00402c65  8b01                 mov eax, dword ptr [ecx]
// 00402c67  8b5014               mov edx, dword ptr [eax + 0x14]
// 00402c6a  6a01                 push 1
// 00402c6c  ffd2                 call edx
// 00402c6e  8bc6                 mov eax, esi
// 00402c70  5e                   pop esi
// 00402c71  c20400               ret 4

struct VCWorkspace_Base0 {
    virtual void f0();
    char pad[0x1c];
};

struct VCWorkspace_Base1 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ~VCWorkspace_Base1();
};

struct VCWorkspace_CComObject : VCWorkspace_Base0, VCWorkspace_Base1
{
    char pad2[0xc];
    int m_refCount;
    static int __stdcall Release(VCWorkspace_CComObject *self);
};

int __stdcall VCWorkspace_CComObject::Release(VCWorkspace_CComObject *self)
{
    int result = --self->m_refCount;
    if (result == 0)
        delete self;
    return result;
}

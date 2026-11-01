// from server: 71% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00564050  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00564050
//
// 00564050  56                   push esi
// 00564051  57                   push edi
// 00564052  8bf9                 mov edi, ecx
// 00564054  e8b78c0000           call 0x56cd10
// 00564059  6a10                 push 0x10
// 0056405b  8907                 mov dword ptr [edi], eax
// 0056405d  8d7704               lea esi, [edi + 4]
// 00564060  e8bbc81300           call 0x6a0920
// 00564065  83c404               add esp, 4
// 00564068  85c0                 test eax, eax
// 0056406a  7411                 je 0x56407d
// 0056406c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00564070  c7001ce28200         mov dword ptr [eax], 0x82e21c
// 00564076  dd01                 fld qword ptr [ecx]
// 00564078  dd5808               fstp qword ptr [eax + 8]
// 0056407b  eb02                 jmp 0x56407f
// 0056407d  33c0                 xor eax, eax
// 0056407f  8d54240c             lea edx, [esp + 0xc]
// 00564083  8bc8                 mov ecx, eax
// 00564085  3bd6                 cmp edx, esi
// 00564087  7404                 je 0x56408d
// 00564089  8b0e                 mov ecx, dword ptr [esi]
// 0056408b  8906                 mov dword ptr [esi], eax
// 0056408d  85c9                 test ecx, ecx
// 0056408f  7408                 je 0x564099
// 00564091  8b01                 mov eax, dword ptr [ecx]
// 00564093  8b10                 mov edx, dword ptr [eax]
// 00564095  6a01                 push 1
// 00564097  ffd2                 call edx
// 00564099  8bc7                 mov eax, edi
// 0056409b  5f                   pop edi
// 0056409c  5e                   pop esi
// 0056409d  c20400               ret 4

struct Holder {
    virtual ~Holder();
};

struct HolderData {
    void* vtable;
    unsigned int padding;
    double value;
};

extern "C" void* __cdecl getDescriptor();
extern "C" void* __cdecl allocate(unsigned int);
extern unsigned int holderVtable[];

struct S {
    void* descriptor;
    Holder* held;

    S* f(const double* value);
};

S* S::f(const double* value)
{
    descriptor = getDescriptor();
    Holder** slot = &held;

    HolderData* p = static_cast<HolderData*>(allocate(16));
    if (p) {
        p->vtable = holderVtable;
        p->value = *value;
    } else {
        p = 0;
    }

    value = reinterpret_cast<const double*>(p);
    Holder* old = reinterpret_cast<Holder*>(p);
    if (reinterpret_cast<void*>(&value) != reinterpret_cast<void*>(slot)) {
        old = *slot;
        *slot = reinterpret_cast<Holder*>(p);
    }
    if (old)
        delete old;

    return this;
}

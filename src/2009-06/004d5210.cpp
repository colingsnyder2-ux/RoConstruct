// from server: 100% by EspClaude
// from server: 71% by EspClaude
// roc 2009-06 004d5210  unit: RBX::VNetworkSettings::?$FactoryProduct  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d5210
//
// 004d5210  ff0514a7a400         inc dword ptr [0xa4a714]
// 004d5216  56                   push esi
// 004d5217  57                   push edi
// 004d5218  8bf1                 mov esi, ecx
// 004d521a  e8010a1100           call 0x5e5c20
// 004d521f  6a10                 push 0x10
// 004d5221  8906                 mov dword ptr [esi], eax
// 004d5223  8d7e04               lea edi, [esi + 4]
// 004d5226  e80d382400           call 0x718a38
// 004d522b  83c404               add esp, 4
// 004d522e  85c0                 test eax, eax
// 004d5230  7411                 je 0x4d5243
// 004d5232  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d5236  c70084498c00         mov dword ptr [eax], 0x8c4984
// 004d523c  dd01                 fld qword ptr [ecx]
// 004d523e  dd5808               fstp qword ptr [eax + 8]
// 004d5241  eb02                 jmp 0x4d5245
// 004d5243  33c0                 xor eax, eax
// 004d5245  8d54240c             lea edx, [esp + 0xc]
// 004d5249  8bc8                 mov ecx, eax
// 004d524b  3bd7                 cmp edx, edi
// 004d524d  7404                 je 0x4d5253
// 004d524f  8b0f                 mov ecx, dword ptr [edi]
// 004d5251  8907                 mov dword ptr [edi], eax
// 004d5253  85c9                 test ecx, ecx
// 004d5255  7408                 je 0x4d525f
// 004d5257  8b01                 mov eax, dword ptr [ecx]
// 004d5259  8b10                 mov edx, dword ptr [eax]
// 004d525b  6a01                 push 1
// 004d525d  ffd2                 call edx
// 004d525f  5f                   pop edi
// 004d5260  8bc6                 mov eax, esi
// 004d5262  5e                   pop esi
// 004d5263  c20400               ret 4

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
extern int exeCounterDouble;

struct S {
    void* descriptor;
    Holder* held;

    S* f(const double* value);
};

S* S::f(const double* value)
{
    ++exeCounterDouble;
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

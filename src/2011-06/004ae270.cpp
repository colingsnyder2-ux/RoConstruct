// from server: 100% by Yeetserama
// roc 2011-06 004ae270  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004ae270
//
// 004ae270  6aff                 push -1
// 004ae272  6861b49d00           push 0x9db461
// 004ae277  64a100000000         mov eax, dword ptr fs:[0]
// 004ae27d  50                   push eax
// 004ae27e  64892500000000       mov dword ptr fs:[0], esp
// 004ae285  83ec0c               sub esp, 0xc
// 004ae288  56                   push esi
// 004ae289  8bf1                 mov esi, ecx
// 004ae28b  c744240400000000     mov dword ptr [esp + 4], 0
// 004ae293  8b06                 mov eax, dword ptr [esi]
// 004ae295  8b4008               mov eax, dword ptr [eax + 8]
// 004ae298  50                   push eax
// 004ae299  b970acc000           mov ecx, 0xc0ac70
// 004ae29e  ff15500aa400         call dword ptr [0xa40a50]
// 004ae2a4  84c0                 test al, al
// 004ae2a6  743e                 je 0x4ae2e6
// 004ae2a8  83c604               add esi, 4
// 004ae2ab  56                   push esi
// 004ae2ac  e8dfb0f6ff           call 0x419390
// 004ae2b1  8b08                 mov ecx, dword ptr [eax]
// 004ae2b3  8b542424             mov edx, dword ptr [esp + 0x24]
// 004ae2b7  890a                 mov dword ptr [edx], ecx
// 004ae2b9  8b4804               mov ecx, dword ptr [eax + 4]
// 004ae2bc  83c404               add esp, 4
// 004ae2bf  894a04               mov dword ptr [edx + 4], ecx
// 004ae2c2  85c9                 test ecx, ecx
// 004ae2c4  740c                 je 0x4ae2d2
// 004ae2c6  83c104               add ecx, 4
// 004ae2c9  b801000000           mov eax, 1
// 004ae2ce  f00fc101             lock xadd dword ptr [ecx], eax
// 004ae2d2  8bc2                 mov eax, edx
// 004ae2d4  5e                   pop esi
// 004ae2d5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ae2d9  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae2e0  83c418               add esp, 0x18
// 004ae2e3  c20400               ret 4
// 004ae2e6  8b0e                 mov ecx, dword ptr [esi]
// 004ae2e8  894c2408             mov dword ptr [esp + 8], ecx
// 004ae2ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae2ef  85c9                 test ecx, ecx
// 004ae2f1  7409                 je 0x4ae2fc
// 004ae2f3  8b11                 mov edx, dword ptr [ecx]
// 004ae2f5  8b4208               mov eax, dword ptr [edx + 8]
// 004ae2f8  ffd0                 call eax
// 004ae2fa  eb02                 jmp 0x4ae2fe
// 004ae2fc  33c0                 xor eax, eax
// 004ae2fe  8944240c             mov dword ptr [esp + 0xc], eax
// 004ae302  8d4c2408             lea ecx, [esp + 8]
// 004ae306  c744241801000000     mov dword ptr [esp + 0x18], 1
// 004ae30e  e8cdd81000           call 0x5bbbe0
// 004ae313  8b08                 mov ecx, dword ptr [eax]
// 004ae315  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ae319  890e                 mov dword ptr [esi], ecx
// 004ae31b  8b4004               mov eax, dword ptr [eax + 4]
// 004ae31e  894604               mov dword ptr [esi + 4], eax
// 004ae321  85c0                 test eax, eax
// 004ae323  740c                 je 0x4ae331
// 004ae325  83c004               add eax, 4
// 004ae328  ba01000000           mov edx, 1
// 004ae32d  f00fc110             lock xadd dword ptr [eax], edx
// 004ae331  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ae335  c744240401000000     mov dword ptr [esp + 4], 1
// 004ae33d  c644241800           mov byte ptr [esp + 0x18], 0
// 004ae342  85c9                 test ecx, ecx
// 004ae344  7408                 je 0x4ae34e
// 004ae346  8b01                 mov eax, dword ptr [ecx]
// 004ae348  8b10                 mov edx, dword ptr [eax]
// 004ae34a  6a01                 push 1
// 004ae34c  ffd2                 call edx
// 004ae34e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ae352  8bc6                 mov eax, esi
// 004ae354  5e                   pop esi
// 004ae355  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae35c  83c418               add esp, 0x18
// 004ae35f  c20400               ret 4
// copied from an identical function in another client (function ?get@Value@ns_ROCX000001@@QAE?AUShared@2@XZ)

namespace ns_ROCX000001 {
// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

class type_info;

typedef bool (__thiscall *TypeEqual)(const type_info*, const type_info&);
extern TypeEqual type_equal;
extern type_info shared_type;

struct TypeDescriptor {
    unsigned char padding[8];
    const type_info* type;
};

struct Holder {
    virtual ~Holder();
    virtual void unused();
    virtual Holder* clone() const;
};

struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        _InterlockedIncrement(&control->references);
    }
}

extern Shared* __cdecl extract_shared(Holder**);

struct Value {
    TypeDescriptor* descriptor;
    Holder* holder;

    Value(const Value&);
    ~Value();
    Shared* converted();
    Shared get();
};

Value::Value(const Value& other)
{
    descriptor = other.descriptor;
    Holder* source = other.holder;
    Holder* copy;
    if (source)
        copy = source->clone();
    else
        copy = 0;
    holder = copy;
}

Value::~Value()
{
    if (holder)
        delete holder;
}

Shared Value::get()
{
    TypeDescriptor* d = descriptor;
    if (type_equal(&shared_type, *d->type))
        return *extract_shared(&holder);

    Value temporary(*this);
    return *temporary.converted();
}
}

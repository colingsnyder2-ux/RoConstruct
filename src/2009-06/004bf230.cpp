// from server: 100% by EspClaude
// roc 2009-06 004bf230  unit: rbx::signals::Z::$$A6AXN::?$signal::slot  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004bf230
//
// 004bf230  6aff                 push -1
// 004bf232  6871948500           push 0x859471
// 004bf237  64a100000000         mov eax, dword ptr fs:[0]
// 004bf23d  50                   push eax
// 004bf23e  64892500000000       mov dword ptr fs:[0], esp
// 004bf245  83ec0c               sub esp, 0xc
// 004bf248  56                   push esi
// 004bf249  8bf1                 mov esi, ecx
// 004bf24b  c744240400000000     mov dword ptr [esp + 4], 0
// 004bf253  8b06                 mov eax, dword ptr [esi]
// 004bf255  8b4008               mov eax, dword ptr [eax + 8]
// 004bf258  50                   push eax
// 004bf259  b9e0d39e00           mov ecx, 0x9ed3e0
// 004bf25e  ff15a4e98900         call dword ptr [0x89e9a4]
// 004bf264  84c0                 test al, al
// 004bf266  743e                 je 0x4bf2a6
// 004bf268  83c604               add esi, 4
// 004bf26b  56                   push esi
// 004bf26c  e80fbdffff           call 0x4baf80
// 004bf271  8b08                 mov ecx, dword ptr [eax]
// 004bf273  8b542424             mov edx, dword ptr [esp + 0x24]
// 004bf277  890a                 mov dword ptr [edx], ecx
// 004bf279  8b4804               mov ecx, dword ptr [eax + 4]
// 004bf27c  83c404               add esp, 4
// 004bf27f  894a04               mov dword ptr [edx + 4], ecx
// 004bf282  85c9                 test ecx, ecx
// 004bf284  740c                 je 0x4bf292
// 004bf286  83c104               add ecx, 4
// 004bf289  b801000000           mov eax, 1
// 004bf28e  f00fc101             lock xadd dword ptr [ecx], eax
// 004bf292  8bc2                 mov eax, edx
// 004bf294  5e                   pop esi
// 004bf295  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004bf299  64890d00000000       mov dword ptr fs:[0], ecx
// 004bf2a0  83c418               add esp, 0x18
// 004bf2a3  c20400               ret 4
// 004bf2a6  8b0e                 mov ecx, dword ptr [esi]
// 004bf2a8  894c2408             mov dword ptr [esp + 8], ecx
// 004bf2ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004bf2af  85c9                 test ecx, ecx
// 004bf2b1  7409                 je 0x4bf2bc
// 004bf2b3  8b11                 mov edx, dword ptr [ecx]
// 004bf2b5  8b4208               mov eax, dword ptr [edx + 8]
// 004bf2b8  ffd0                 call eax
// 004bf2ba  eb02                 jmp 0x4bf2be
// 004bf2bc  33c0                 xor eax, eax
// 004bf2be  8944240c             mov dword ptr [esp + 0xc], eax
// 004bf2c2  8d4c2408             lea ecx, [esp + 8]
// 004bf2c6  c744241801000000     mov dword ptr [esp + 0x18], 1
// 004bf2ce  e8ad7b1200           call 0x5e6e80
// 004bf2d3  8b08                 mov ecx, dword ptr [eax]
// 004bf2d5  8b742420             mov esi, dword ptr [esp + 0x20]
// 004bf2d9  890e                 mov dword ptr [esi], ecx
// 004bf2db  8b4004               mov eax, dword ptr [eax + 4]
// 004bf2de  894604               mov dword ptr [esi + 4], eax
// 004bf2e1  85c0                 test eax, eax
// 004bf2e3  740c                 je 0x4bf2f1
// 004bf2e5  83c004               add eax, 4
// 004bf2e8  ba01000000           mov edx, 1
// 004bf2ed  f00fc110             lock xadd dword ptr [eax], edx
// 004bf2f1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004bf2f5  c744240401000000     mov dword ptr [esp + 4], 1
// 004bf2fd  c644241800           mov byte ptr [esp + 0x18], 0
// 004bf302  85c9                 test ecx, ecx
// 004bf304  7408                 je 0x4bf30e
// 004bf306  8b01                 mov eax, dword ptr [ecx]
// 004bf308  8b10                 mov edx, dword ptr [eax]
// 004bf30a  6a01                 push 1
// 004bf30c  ffd2                 call edx
// 004bf30e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bf312  8bc6                 mov eax, esi
// 004bf314  5e                   pop esi
// 004bf315  64890d00000000       mov dword ptr fs:[0], ecx
// 004bf31c  83c418               add esp, 0x18
// 004bf31f  c20400               ret 4
// copied from an identical function in another client (function ?get@Value@ns_ROCX00000d@@QAE?AUShared@2@XZ)

namespace ns_ROCX00000d {
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

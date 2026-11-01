// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005db040  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db040
//
// 005db040  64a100000000         mov eax, dword ptr fs:[0]
// 005db046  6aff                 push -1
// 005db048  68185f7d00           push 0x7d5f18
// 005db04d  50                   push eax
// 005db04e  64892500000000       mov dword ptr fs:[0], esp
// 005db055  56                   push esi
// 005db056  8bf1                 mov esi, ecx
// 005db058  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005db05c  e85f48f9ff           call 0x56f8c0
// 005db061  8b10                 mov edx, dword ptr [eax]
// 005db063  83ec08               sub esp, 8
// 005db066  8bcc                 mov ecx, esp
// 005db068  8911                 mov dword ptr [ecx], edx
// 005db06a  8b4004               mov eax, dword ptr [eax + 4]
// 005db06d  89642428             mov dword ptr [esp + 0x28], esp
// 005db071  894104               mov dword ptr [ecx + 4], eax
// 005db074  85c0                 test eax, eax
// 005db076  740c                 je 0x5db084
// 005db078  83c004               add eax, 4
// 005db07b  b901000000           mov ecx, 1
// 005db080  f00fc108             lock xadd dword ptr [eax], ecx
// 005db084  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005db088  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005db090  e80b3ff9ff           call 0x56efa0
// 005db095  d900                 fld dword ptr [eax]
// 005db097  83ec0c               sub esp, 0xc
// 005db09a  8bcc                 mov ecx, esp
// 005db09c  d919                 fstp dword ptr [ecx]
// 005db09e  89642434             mov dword ptr [esp + 0x34], esp
// 005db0a2  d94004               fld dword ptr [eax + 4]
// 005db0a5  d95904               fstp dword ptr [ecx + 4]
// 005db0a8  d94008               fld dword ptr [eax + 8]
// 005db0ab  8b442428             mov eax, dword ptr [esp + 0x28]
// 005db0af  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 005db0b5  d95908               fstp dword ptr [ecx + 8]
// 005db0b8  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005db0bb  8b140a               mov edx, dword ptr [edx + ecx]
// 005db0be  03563c               add edx, dword ptr [esi + 0x3c]
// 005db0c1  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 005db0c9  8d8c0250010000       lea ecx, [edx + eax + 0x150]
// 005db0d0  8b4638               mov eax, dword ptr [esi + 0x38]
// 005db0d3  ffd0                 call eax
// 005db0d5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005db0d9  64890d00000000       mov dword ptr fs:[0], ecx
// 005db0e0  5e                   pop esi
// 005db0e1  83c40c               add esp, 0xc
// 005db0e4  c21000               ret 0x10

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* value)
{
    _InterlockedExchangeAdd(value, 1);
}

struct Control {
    long unused;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Vector {
    float x, y, z;

    Vector(const Vector&);
};

__forceinline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct VectorArgument {
    const Vector& get();
};

struct SharedArgument {
    const Shared& get();
};

struct VirtualBase {
};

struct Target : virtual VirtualBase {
};

typedef void (Target::*Method)(Vector, Shared);

struct Object {
    char padding[0x140];
    Target target;
};

struct Descriptor {
    char padding[0x38];
    Method method;

    void invoke(Object*, void*, VectorArgument*, SharedArgument*);
};

void Descriptor::invoke(Object* object, void*, VectorArgument* vector,
                        SharedArgument* shared)
{
    (object->target.*method)(vector->get(), shared->get());
}

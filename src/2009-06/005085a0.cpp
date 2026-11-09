// from server: 100% by EspClaude
// roc 2009-06 005085a0  unit: RBX::Network::PhysicsSender::Job  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005085a0
//
// 005085a0  6aff                 push -1
// 005085a2  68f89c8500           push 0x859cf8
// 005085a7  64a100000000         mov eax, dword ptr fs:[0]
// 005085ad  50                   push eax
// 005085ae  64892500000000       mov dword ptr fs:[0], esp
// 005085b5  51                   push ecx
// 005085b6  53                   push ebx
// 005085b7  55                   push ebp
// 005085b8  56                   push esi
// 005085b9  57                   push edi
// 005085ba  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005085be  8b07                 mov eax, dword ptr [edi]
// 005085c0  8bf1                 mov esi, ecx
// 005085c2  8906                 mov dword ptr [esi], eax
// 005085c4  8b4704               mov eax, dword ptr [edi + 4]
// 005085c7  89742410             mov dword ptr [esp + 0x10], esi
// 005085cb  894604               mov dword ptr [esi + 4], eax
// 005085ce  85c0                 test eax, eax
// 005085d0  740c                 je 0x5085de
// 005085d2  83c004               add eax, 4
// 005085d5  b901000000           mov ecx, 1
// 005085da  f00fc108             lock xadd dword ptr [eax], ecx
// 005085de  dd4708               fld qword ptr [edi + 8]
// 005085e1  8d5f10               lea ebx, [edi + 0x10]
// 005085e4  dd5e08               fstp qword ptr [esi + 8]
// 005085e7  8d6e10               lea ebp, [esi + 0x10]
// 005085ea  53                   push ebx
// 005085eb  8bcd                 mov ecx, ebp
// 005085ed  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005085f5  e88619f9ff           call 0x499f80
// 005085fa  d94324               fld dword ptr [ebx + 0x24]
// 005085fd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00508601  d95d24               fstp dword ptr [ebp + 0x24]
// 00508604  d94328               fld dword ptr [ebx + 0x28]
// 00508607  8bc6                 mov eax, esi
// 00508609  d95d28               fstp dword ptr [ebp + 0x28]
// 0050860c  d9432c               fld dword ptr [ebx + 0x2c]
// 0050860f  d95d2c               fstp dword ptr [ebp + 0x2c]
// 00508612  d94740               fld dword ptr [edi + 0x40]
// 00508615  d95e40               fstp dword ptr [esi + 0x40]
// 00508618  8b5744               mov edx, dword ptr [edi + 0x44]
// 0050861b  895644               mov dword ptr [esi + 0x44], edx
// 0050861e  d94748               fld dword ptr [edi + 0x48]
// 00508621  5f                   pop edi
// 00508622  d95e48               fstp dword ptr [esi + 0x48]
// 00508625  5e                   pop esi
// 00508626  5d                   pop ebp
// 00508627  5b                   pop ebx
// 00508628  64890d00000000       mov dword ptr fs:[0], ecx
// 0050862f  83c410               add esp, 0x10
// 00508632  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX00001f@@QAE@ABU01@@Z)

namespace ns_ROCX00001f {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* counter)
{
    _InterlockedExchangeAdd(counter, 1);
}

struct ControlBlock {
    long reserved;
    volatile long references;
};

struct SharedHandle {
    void* object;
    ControlBlock* control;

    SharedHandle(const SharedHandle&);
    ~SharedHandle();
};

__forceinline SharedHandle::SharedHandle(const SharedHandle& other)
    : object(other.object), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Matrix {
    float values[9];
    Matrix(const Matrix&);
};

struct Camera {
    Matrix rotation;
    float x;
    float y;
    float z;
};

struct S {
    SharedHandle handle;
    double time;
    Camera camera;
    float value;
    int flags;
    float weight;

    S(const S&);
};

S::S(const S& other)
    : handle(other.handle),
      time(other.time),
      camera(other.camera),
      value(other.value),
      flags(other.flags),
      weight(other.weight)
{
}
}

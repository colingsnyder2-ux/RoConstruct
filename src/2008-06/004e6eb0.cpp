// from server: 100% by colin
// from server: 91% by colin
// roc 2008-06 004e6eb0  unit: RBX::ViewNew::PartChunk  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6eb0
//
// 004e6eb0  6aff                 push -1
// 004e6eb2  684ba57c00           push 0x7ca54b
// 004e6eb7  64a100000000         mov eax, dword ptr fs:[0]
// 004e6ebd  50                   push eax
// 004e6ebe  64892500000000       mov dword ptr fs:[0], esp
// 004e6ec5  83ec08               sub esp, 8
// 004e6ec8  56                   push esi
// 004e6ec9  57                   push edi
// 004e6eca  6a24                 push 0x24
// 004e6ecc  8bf1                 mov esi, ecx
// 004e6ece  e85d160200           call 0x508530
// 004e6ed3  8bf8                 mov edi, eax
// 004e6ed5  83c404               add esp, 4
// 004e6ed8  897c2408             mov dword ptr [esp + 8], edi
// 004e6edc  33c0                 xor eax, eax
// 004e6ede  89442418             mov dword ptr [esp + 0x18], eax
// 004e6ee2  3bf8                 cmp edi, eax
// 004e6ee4  7452                 je 0x4e6f38
// 004e6ee6  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004e6ee9  3bc8                 cmp ecx, eax
// 004e6eeb  7405                 je 0x4e6ef2
// 004e6eed  e8beffffff           call 0x4e6eb0
// 004e6ef2  50                   push eax
// 004e6ef3  8b06                 mov eax, dword ptr [esi]
// 004e6ef5  50                   push eax
// 004e6ef6  83ec10               sub esp, 0x10
// 004e6ef9  89642424             mov dword ptr [esp + 0x24], esp
// 004e6efd  8bc4                 mov eax, esp
// 004e6eff  68702a5000           push 0x502a70
// 004e6f04  6820084f00           push 0x4f0820
// 004e6f09  6a04                 push 4
// 004e6f0b  6a04                 push 4
// 004e6f0d  8d4e10               lea ecx, [esi + 0x10]
// 004e6f10  51                   push ecx
// 004e6f11  50                   push eax
// 004e6f12  e89fac1b00           call 0x6a1bb6
// 004e6f17  d94604               fld dword ptr [esi + 4]
// 004e6f1a  83ec0c               sub esp, 0xc
// 004e6f1d  8bc4                 mov eax, esp
// 004e6f1f  d918                 fstp dword ptr [eax]
// 004e6f21  8bcf                 mov ecx, edi
// 004e6f23  d94608               fld dword ptr [esi + 8]
// 004e6f26  89642430             mov dword ptr [esp + 0x30], esp
// 004e6f2a  d95804               fstp dword ptr [eax + 4]
// 004e6f2d  d9460c               fld dword ptr [esi + 0xc]
// 004e6f30  d95808               fstp dword ptr [eax + 8]
// 004e6f33  e818feffff           call 0x4e6d50
// 004e6f38  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e6f3c  5f                   pop edi
// 004e6f3d  64890d00000000       mov dword ptr fs:[0], ecx
// 004e6f44  5e                   pop esi
// 004e6f45  83c414               add esp, 0x14
// 004e6f48  c3                   ret 

//

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern "C" void __stdcall copy_element(void*, const void*);
extern "C" void __stdcall destroy_element(void*);
extern "C" void __stdcall copy_array(
    void*, const void*, unsigned int, int,
    void (__stdcall *)(void*, const void*),
    void (__stdcall *)(void*));

struct Handle {
    unsigned int value[4];
    Handle(const Handle&);
};

inline Handle::Handle(const Handle& other)
{
    copy_array(this, &other, 4, 4, copy_element, destroy_element);
}

struct Vector {
    float x, y, z;
    Vector(const Vector&);
};

inline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct S {
    int value;
    Vector position;
    Handle handle;
    S* child;

    S(Vector, Handle, int, S*);
    S* clone();
};

S* S::clone()
{
    return new S(position, handle, value, child ? child->clone() : 0);
}

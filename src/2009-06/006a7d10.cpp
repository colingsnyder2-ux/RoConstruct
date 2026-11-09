// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fa970  unit: UString_sink::?$stream_buffer  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fa970
//
// 005fa970  6aff                 push -1
// 005fa972  68597d7d00           push 0x7d7d59
// 005fa977  64a100000000         mov eax, dword ptr fs:[0]
// 005fa97d  50                   push eax
// 005fa97e  64892500000000       mov dword ptr fs:[0], esp
// 005fa985  51                   push ecx
// 005fa986  53                   push ebx
// 005fa987  56                   push esi
// 005fa988  8bf1                 mov esi, ecx
// 005fa98a  89742408             mov dword ptr [esp + 8], esi
// 005fa98e  8b4630               mov eax, dword ptr [esi + 0x30]
// 005fa991  50                   push eax
// 005fa992  c744241803000000     mov dword ptr [esp + 0x18], 3
// 005fa99a  e881d3f0ff           call 0x507d20
// 005fa99f  33db                 xor ebx, ebx
// 005fa9a1  895e30               mov dword ptr [esi + 0x30], ebx
// 005fa9a4  895e34               mov dword ptr [esi + 0x34], ebx
// 005fa9a7  895e38               mov dword ptr [esi + 0x38], ebx
// 005fa9aa  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 005fa9ad  51                   push ecx
// 005fa9ae  c644241c02           mov byte ptr [esp + 0x1c], 2
// 005fa9b3  e868d3f0ff           call 0x507d20
// 005fa9b8  895e24               mov dword ptr [esi + 0x24], ebx
// 005fa9bb  895e28               mov dword ptr [esi + 0x28], ebx
// 005fa9be  895e2c               mov dword ptr [esi + 0x2c], ebx
// 005fa9c1  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fa9c4  52                   push edx
// 005fa9c5  c644242001           mov byte ptr [esp + 0x20], 1
// 005fa9ca  e851d3f0ff           call 0x507d20
// 005fa9cf  895e18               mov dword ptr [esi + 0x18], ebx
// 005fa9d2  895e1c               mov dword ptr [esi + 0x1c], ebx
// 005fa9d5  895e20               mov dword ptr [esi + 0x20], ebx
// 005fa9d8  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fa9db  50                   push eax
// 005fa9dc  885c2424             mov byte ptr [esp + 0x24], bl
// 005fa9e0  e83bd3f0ff           call 0x507d20
// 005fa9e5  895e0c               mov dword ptr [esi + 0xc], ebx
// 005fa9e8  895e10               mov dword ptr [esi + 0x10], ebx
// 005fa9eb  895e14               mov dword ptr [esi + 0x14], ebx
// 005fa9ee  8b0e                 mov ecx, dword ptr [esi]
// 005fa9f0  51                   push ecx
// 005fa9f1  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 005fa9f9  e822d3f0ff           call 0x507d20
// 005fa9fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005faa02  83c414               add esp, 0x14
// 005faa05  891e                 mov dword ptr [esi], ebx
// 005faa07  895e04               mov dword ptr [esi + 4], ebx
// 005faa0a  895e08               mov dword ptr [esi + 8], ebx
// 005faa0d  5e                   pop esi
// 005faa0e  5b                   pop ebx
// 005faa0f  64890d00000000       mov dword ptr fs:[0], ecx
// 005faa16  83c410               add esp, 0x10
// 005faa19  c3                   ret 

namespace G3D {
    struct System {
        static void __cdecl alignedFree(void*);
    };
}

struct Buffer {
    void* data;
    int size;
    int capacity;
    ~Buffer();
};

__forceinline Buffer::~Buffer()
{
    G3D::System::alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct S {
    Buffer a;
    Buffer b;
    Buffer c;
    Buffer d;
    Buffer e;
    ~S();
};

S::~S()
{
}

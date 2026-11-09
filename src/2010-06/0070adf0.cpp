// from server: 100% by Yeetserama
// roc 2010-06 0070adf0  unit: RBX::RbxG3D::Material::Level  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0070adf0
//
// 0070adf0  6aff                 push -1
// 0070adf2  6889e19800           push 0x98e189
// 0070adf7  64a100000000         mov eax, dword ptr fs:[0]
// 0070adfd  50                   push eax
// 0070adfe  64892500000000       mov dword ptr fs:[0], esp
// 0070ae05  51                   push ecx
// 0070ae06  53                   push ebx
// 0070ae07  56                   push esi
// 0070ae08  8bf1                 mov esi, ecx
// 0070ae0a  89742408             mov dword ptr [esp + 8], esi
// 0070ae0e  8b4630               mov eax, dword ptr [esi + 0x30]
// 0070ae11  50                   push eax
// 0070ae12  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0070ae1a  e8a12be4ff           call 0x54d9c0
// 0070ae1f  33db                 xor ebx, ebx
// 0070ae21  895e30               mov dword ptr [esi + 0x30], ebx
// 0070ae24  895e34               mov dword ptr [esi + 0x34], ebx
// 0070ae27  895e38               mov dword ptr [esi + 0x38], ebx
// 0070ae2a  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0070ae2d  51                   push ecx
// 0070ae2e  c644241c02           mov byte ptr [esp + 0x1c], 2
// 0070ae33  e8882be4ff           call 0x54d9c0
// 0070ae38  895e24               mov dword ptr [esi + 0x24], ebx
// 0070ae3b  895e28               mov dword ptr [esi + 0x28], ebx
// 0070ae3e  895e2c               mov dword ptr [esi + 0x2c], ebx
// 0070ae41  8b5618               mov edx, dword ptr [esi + 0x18]
// 0070ae44  52                   push edx
// 0070ae45  c644242001           mov byte ptr [esp + 0x20], 1
// 0070ae4a  e8712be4ff           call 0x54d9c0
// 0070ae4f  895e18               mov dword ptr [esi + 0x18], ebx
// 0070ae52  895e1c               mov dword ptr [esi + 0x1c], ebx
// 0070ae55  895e20               mov dword ptr [esi + 0x20], ebx
// 0070ae58  8b460c               mov eax, dword ptr [esi + 0xc]
// 0070ae5b  50                   push eax
// 0070ae5c  885c2424             mov byte ptr [esp + 0x24], bl
// 0070ae60  e85b2be4ff           call 0x54d9c0
// 0070ae65  895e0c               mov dword ptr [esi + 0xc], ebx
// 0070ae68  895e10               mov dword ptr [esi + 0x10], ebx
// 0070ae6b  895e14               mov dword ptr [esi + 0x14], ebx
// 0070ae6e  8b0e                 mov ecx, dword ptr [esi]
// 0070ae70  51                   push ecx
// 0070ae71  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0070ae79  e8422be4ff           call 0x54d9c0
// 0070ae7e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0070ae82  83c414               add esp, 0x14
// 0070ae85  891e                 mov dword ptr [esi], ebx
// 0070ae87  895e04               mov dword ptr [esi + 4], ebx
// 0070ae8a  895e08               mov dword ptr [esi + 8], ebx
// 0070ae8d  5e                   pop esi
// 0070ae8e  5b                   pop ebx
// 0070ae8f  64890d00000000       mov dword ptr fs:[0], ecx
// 0070ae96  83c410               add esp, 0x10
// 0070ae99  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00000d@@QAE@XZ)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
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
}

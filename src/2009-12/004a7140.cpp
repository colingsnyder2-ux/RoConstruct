// from server: 100% by auto
// roc 2009-12 004a7140  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a7140
//
// 004a7140  83ec08               sub esp, 8
// 004a7143  53                   push ebx
// 004a7144  55                   push ebp
// 004a7145  56                   push esi
// 004a7146  8bf1                 mov esi, ecx
// 004a7148  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a714b  57                   push edi
// 004a714c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a714f  8bcb                 mov ecx, ebx
// 004a7151  2bcf                 sub ecx, edi
// 004a7153  b8398ee338           mov eax, 0x38e38e39
// 004a7158  f7e9                 imul ecx
// 004a715a  c1fa03               sar edx, 3
// 004a715d  8bc2                 mov eax, edx
// 004a715f  c1e81f               shr eax, 0x1f
// 004a7162  03c2                 add eax, edx
// 004a7164  7504                 jne 0x4a716a
// 004a7166  33ff                 xor edi, edi
// 004a7168  eb35                 jmp 0x4a719f
// 004a716a  3bfb                 cmp edi, ebx
// 004a716c  7606                 jbe 0x4a7174
// 004a716e  ff1560b79800         call dword ptr [0x98b760]
// 004a7174  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a7178  8b06                 mov eax, dword ptr [esi]
// 004a717a  85c9                 test ecx, ecx
// 004a717c  7404                 je 0x4a7182
// 004a717e  3bc8                 cmp ecx, eax
// 004a7180  7406                 je 0x4a7188
// 004a7182  ff1560b79800         call dword ptr [0x98b760]
// 004a7188  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a718c  2bcf                 sub ecx, edi
// 004a718e  b8398ee338           mov eax, 0x38e38e39
// 004a7193  f7e9                 imul ecx
// 004a7195  c1fa03               sar edx, 3
// 004a7198  8bfa                 mov edi, edx
// 004a719a  c1ef1f               shr edi, 0x1f
// 004a719d  03fa                 add edi, edx
// 004a719f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a71a3  8b542424             mov edx, dword ptr [esp + 0x24]
// 004a71a7  8b442420             mov eax, dword ptr [esp + 0x20]
// 004a71ab  51                   push ecx
// 004a71ac  6a01                 push 1
// 004a71ae  52                   push edx
// 004a71af  50                   push eax
// 004a71b0  8bce                 mov ecx, esi
// 004a71b2  e819c8ffff           call 0x4a39d0
// 004a71b7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a71ba  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004a71bd  7606                 jbe 0x4a71c5
// 004a71bf  ff1560b79800         call dword ptr [0x98b760]
// 004a71c5  8b36                 mov esi, dword ptr [esi]
// 004a71c7  8bee                 mov ebp, esi
// 004a71c9  895c2414             mov dword ptr [esp + 0x14], ebx
// 004a71cd  85f6                 test esi, esi
// 004a71cf  751b                 jne 0x4a71ec
// 004a71d1  ff1560b79800         call dword ptr [0x98b760]
// 004a71d7  33c0                 xor eax, eax
// 004a71d9  8d0cff               lea ecx, [edi + edi*8]
// 004a71dc  8d3c8b               lea edi, [ebx + ecx*4]
// 004a71df  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004a71e2  7713                 ja 0x4a71f7
// 004a71e4  85f6                 test esi, esi
// 004a71e6  7408                 je 0x4a71f0
// 004a71e8  8b36                 mov esi, dword ptr [esi]
// 004a71ea  eb06                 jmp 0x4a71f2
// 004a71ec  8b06                 mov eax, dword ptr [esi]
// 004a71ee  ebe9                 jmp 0x4a71d9
// 004a71f0  33f6                 xor esi, esi
// 004a71f2  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004a71f5  7306                 jae 0x4a71fd
// 004a71f7  ff1560b79800         call dword ptr [0x98b760]
// 004a71fd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a7201  897804               mov dword ptr [eax + 4], edi
// 004a7204  5f                   pop edi
// 004a7205  5e                   pop esi
// 004a7206  8928                 mov dword ptr [eax], ebp
// 004a7208  5d                   pop ebp
// 004a7209  5b                   pop ebx
// 004a720a  83c408               add esp, 8
// 004a720d  c21000               ret 0x10
// standard library vector<pod36> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2010-06 008d6f00  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6f00
//
// 008d6f00  83ec08               sub esp, 8
// 008d6f03  53                   push ebx
// 008d6f04  55                   push ebp
// 008d6f05  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008d6f0b  56                   push esi
// 008d6f0c  8bf1                 mov esi, ecx
// 008d6f0e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008d6f11  57                   push edi
// 008d6f12  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008d6f15  8bcb                 mov ecx, ebx
// 008d6f17  2bcf                 sub ecx, edi
// 008d6f19  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d6f1e  f7e9                 imul ecx
// 008d6f20  c1fa02               sar edx, 2
// 008d6f23  8bc2                 mov eax, edx
// 008d6f25  c1e81f               shr eax, 0x1f
// 008d6f28  03c2                 add eax, edx
// 008d6f2a  7504                 jne 0x8d6f30
// 008d6f2c  33ff                 xor edi, edi
// 008d6f2e  eb2d                 jmp 0x8d6f5d
// 008d6f30  3bfb                 cmp edi, ebx
// 008d6f32  7602                 jbe 0x8d6f36
// 008d6f34  ffd5                 call ebp
// 008d6f36  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d6f3a  8b06                 mov eax, dword ptr [esi]
// 008d6f3c  85c9                 test ecx, ecx
// 008d6f3e  7404                 je 0x8d6f44
// 008d6f40  3bc8                 cmp ecx, eax
// 008d6f42  7402                 je 0x8d6f46
// 008d6f44  ffd5                 call ebp
// 008d6f46  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d6f4a  2bcf                 sub ecx, edi
// 008d6f4c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d6f51  f7e9                 imul ecx
// 008d6f53  c1fa02               sar edx, 2
// 008d6f56  8bfa                 mov edi, edx
// 008d6f58  c1ef1f               shr edi, 0x1f
// 008d6f5b  03fa                 add edi, edx
// 008d6f5d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d6f61  8b542424             mov edx, dword ptr [esp + 0x24]
// 008d6f65  8b442420             mov eax, dword ptr [esp + 0x20]
// 008d6f69  51                   push ecx
// 008d6f6a  6a01                 push 1
// 008d6f6c  52                   push edx
// 008d6f6d  50                   push eax
// 008d6f6e  8bce                 mov ecx, esi
// 008d6f70  e84bf9ffff           call 0x8d68c0
// 008d6f75  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d6f78  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008d6f7b  7602                 jbe 0x8d6f7f
// 008d6f7d  ffd5                 call ebp
// 008d6f7f  8b36                 mov esi, dword ptr [esi]
// 008d6f81  57                   push edi
// 008d6f82  8d4c2414             lea ecx, [esp + 0x14]
// 008d6f86  89742414             mov dword ptr [esp + 0x14], esi
// 008d6f8a  895c2418             mov dword ptr [esp + 0x18], ebx
// 008d6f8e  e8ed96e5ff           call 0x730680
// 008d6f93  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d6f97  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d6f9b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d6f9f  5f                   pop edi
// 008d6fa0  5e                   pop esi
// 008d6fa1  5d                   pop ebp
// 008d6fa2  8908                 mov dword ptr [eax], ecx
// 008d6fa4  895004               mov dword ptr [eax + 4], edx
// 008d6fa7  5b                   pop ebx
// 008d6fa8  83c408               add esp, 8
// 008d6fab  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2009-12 004bf170  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bf170
//
// 004bf170  83ec08               sub esp, 8
// 004bf173  53                   push ebx
// 004bf174  55                   push ebp
// 004bf175  56                   push esi
// 004bf176  8bf1                 mov esi, ecx
// 004bf178  8b4610               mov eax, dword ptr [esi + 0x10]
// 004bf17b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004bf17e  8bc8                 mov ecx, eax
// 004bf180  2bcb                 sub ecx, ebx
// 004bf182  57                   push edi
// 004bf183  f7c1f0ffffff         test ecx, 0xfffffff0
// 004bf189  7504                 jne 0x4bf18f
// 004bf18b  33ff                 xor edi, edi
// 004bf18d  eb27                 jmp 0x4bf1b6
// 004bf18f  3bd8                 cmp ebx, eax
// 004bf191  7606                 jbe 0x4bf199
// 004bf193  ff1560b79800         call dword ptr [0x98b760]
// 004bf199  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004bf19d  8b06                 mov eax, dword ptr [esi]
// 004bf19f  85c9                 test ecx, ecx
// 004bf1a1  7404                 je 0x4bf1a7
// 004bf1a3  3bc8                 cmp ecx, eax
// 004bf1a5  7406                 je 0x4bf1ad
// 004bf1a7  ff1560b79800         call dword ptr [0x98b760]
// 004bf1ad  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004bf1b1  2bfb                 sub edi, ebx
// 004bf1b3  c1ff04               sar edi, 4
// 004bf1b6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004bf1ba  8b442424             mov eax, dword ptr [esp + 0x24]
// 004bf1be  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004bf1c2  52                   push edx
// 004bf1c3  6a01                 push 1
// 004bf1c5  50                   push eax
// 004bf1c6  51                   push ecx
// 004bf1c7  8bce                 mov ecx, esi
// 004bf1c9  e892f3ffff           call 0x4be560
// 004bf1ce  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004bf1d1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004bf1d4  7606                 jbe 0x4bf1dc
// 004bf1d6  ff1560b79800         call dword ptr [0x98b760]
// 004bf1dc  8b36                 mov esi, dword ptr [esi]
// 004bf1de  8bee                 mov ebp, esi
// 004bf1e0  895c2414             mov dword ptr [esp + 0x14], ebx
// 004bf1e4  85f6                 test esi, esi
// 004bf1e6  751a                 jne 0x4bf202
// 004bf1e8  ff1560b79800         call dword ptr [0x98b760]
// 004bf1ee  33c0                 xor eax, eax
// 004bf1f0  c1e704               shl edi, 4
// 004bf1f3  03fb                 add edi, ebx
// 004bf1f5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004bf1f8  7713                 ja 0x4bf20d
// 004bf1fa  85f6                 test esi, esi
// 004bf1fc  7408                 je 0x4bf206
// 004bf1fe  8b36                 mov esi, dword ptr [esi]
// 004bf200  eb06                 jmp 0x4bf208
// 004bf202  8b06                 mov eax, dword ptr [esi]
// 004bf204  ebea                 jmp 0x4bf1f0
// 004bf206  33f6                 xor esi, esi
// 004bf208  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004bf20b  7306                 jae 0x4bf213
// 004bf20d  ff1560b79800         call dword ptr [0x98b760]
// 004bf213  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bf217  897804               mov dword ptr [eax + 4], edi
// 004bf21a  5f                   pop edi
// 004bf21b  5e                   pop esi
// 004bf21c  8928                 mov dword ptr [eax], ebp
// 004bf21e  5d                   pop ebp
// 004bf21f  5b                   pop ebx
// 004bf220  83c408               add esp, 8
// 004bf223  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

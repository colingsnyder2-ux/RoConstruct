// from server: 100% by auto
// roc 2010-06 008d7300  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d7300
//
// 008d7300  83ec08               sub esp, 8
// 008d7303  53                   push ebx
// 008d7304  56                   push esi
// 008d7305  8bf1                 mov esi, ecx
// 008d7307  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d730a  57                   push edi
// 008d730b  85db                 test ebx, ebx
// 008d730d  7504                 jne 0x8d7313
// 008d730f  33c9                 xor ecx, ecx
// 008d7311  eb16                 jmp 0x8d7329
// 008d7313  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008d7316  2bcb                 sub ecx, ebx
// 008d7318  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d731d  f7e9                 imul ecx
// 008d731f  c1fa02               sar edx, 2
// 008d7322  8bca                 mov ecx, edx
// 008d7324  c1e91f               shr ecx, 0x1f
// 008d7327  03ca                 add ecx, edx
// 008d7329  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008d732c  8bd7                 mov edx, edi
// 008d732e  2bd3                 sub edx, ebx
// 008d7330  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d7335  f7ea                 imul edx
// 008d7337  c1fa02               sar edx, 2
// 008d733a  8bc2                 mov eax, edx
// 008d733c  c1e81f               shr eax, 0x1f
// 008d733f  03c2                 add eax, edx
// 008d7341  3bc1                 cmp eax, ecx
// 008d7343  7332                 jae 0x8d7377
// 008d7345  8b542418             mov edx, dword ptr [esp + 0x18]
// 008d7349  c644240c00           mov byte ptr [esp + 0xc], 0
// 008d734e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d7352  51                   push ecx
// 008d7353  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008d7357  52                   push edx
// 008d7358  8d4608               lea eax, [esi + 8]
// 008d735b  50                   push eax
// 008d735c  51                   push ecx
// 008d735d  6a01                 push 1
// 008d735f  57                   push edi
// 008d7360  e80beeffff           call 0x8d6170
// 008d7365  83c418               add esp, 0x18
// 008d7368  83c718               add edi, 0x18
// 008d736b  897e10               mov dword ptr [esi + 0x10], edi
// 008d736e  5f                   pop edi
// 008d736f  5e                   pop esi
// 008d7370  5b                   pop ebx
// 008d7371  83c408               add esp, 8
// 008d7374  c20400               ret 4
// 008d7377  3bdf                 cmp ebx, edi
// 008d7379  7606                 jbe 0x8d7381
// 008d737b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d7381  8b542418             mov edx, dword ptr [esp + 0x18]
// 008d7385  8b06                 mov eax, dword ptr [esi]
// 008d7387  52                   push edx
// 008d7388  57                   push edi
// 008d7389  50                   push eax
// 008d738a  8d442418             lea eax, [esp + 0x18]
// 008d738e  50                   push eax
// 008d738f  8bce                 mov ecx, esi
// 008d7391  e86afbffff           call 0x8d6f00
// 008d7396  5f                   pop edi
// 008d7397  5e                   pop esi
// 008d7398  5b                   pop ebx
// 008d7399  83c408               add esp, 8
// 008d739c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;

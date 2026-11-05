// from server: 100% by auto
// roc 2010-06 008fb410  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fb410
//
// 008fb410  83ec08               sub esp, 8
// 008fb413  53                   push ebx
// 008fb414  56                   push esi
// 008fb415  8bf1                 mov esi, ecx
// 008fb417  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008fb41a  57                   push edi
// 008fb41b  85db                 test ebx, ebx
// 008fb41d  7504                 jne 0x8fb423
// 008fb41f  33c9                 xor ecx, ecx
// 008fb421  eb16                 jmp 0x8fb439
// 008fb423  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008fb426  2bcb                 sub ecx, ebx
// 008fb428  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008fb42d  f7e9                 imul ecx
// 008fb42f  c1fa03               sar edx, 3
// 008fb432  8bca                 mov ecx, edx
// 008fb434  c1e91f               shr ecx, 0x1f
// 008fb437  03ca                 add ecx, edx
// 008fb439  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008fb43c  8bd7                 mov edx, edi
// 008fb43e  2bd3                 sub edx, ebx
// 008fb440  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008fb445  f7ea                 imul edx
// 008fb447  c1fa03               sar edx, 3
// 008fb44a  8bc2                 mov eax, edx
// 008fb44c  c1e81f               shr eax, 0x1f
// 008fb44f  03c2                 add eax, edx
// 008fb451  3bc1                 cmp eax, ecx
// 008fb453  7332                 jae 0x8fb487
// 008fb455  8b542418             mov edx, dword ptr [esp + 0x18]
// 008fb459  c644240c00           mov byte ptr [esp + 0xc], 0
// 008fb45e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008fb462  51                   push ecx
// 008fb463  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008fb467  52                   push edx
// 008fb468  8d4608               lea eax, [esi + 8]
// 008fb46b  50                   push eax
// 008fb46c  51                   push ecx
// 008fb46d  6a01                 push 1
// 008fb46f  57                   push edi
// 008fb470  e82b89ffff           call 0x8f3da0
// 008fb475  83c418               add esp, 0x18
// 008fb478  83c730               add edi, 0x30
// 008fb47b  897e10               mov dword ptr [esi + 0x10], edi
// 008fb47e  5f                   pop edi
// 008fb47f  5e                   pop esi
// 008fb480  5b                   pop ebx
// 008fb481  83c408               add esp, 8
// 008fb484  c20400               ret 4
// 008fb487  3bdf                 cmp ebx, edi
// 008fb489  7606                 jbe 0x8fb491
// 008fb48b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fb491  8b542418             mov edx, dword ptr [esp + 0x18]
// 008fb495  8b06                 mov eax, dword ptr [esi]
// 008fb497  52                   push edx
// 008fb498  57                   push edi
// 008fb499  50                   push eax
// 008fb49a  8d442418             lea eax, [esp + 0x18]
// 008fb49e  50                   push eax
// 008fb49f  8bce                 mov ecx, esi
// 008fb4a1  e8baf7ffff           call 0x8fac60
// 008fb4a6  5f                   pop edi
// 008fb4a7  5e                   pop esi
// 008fb4a8  5b                   pop ebx
// 008fb4a9  83c408               add esp, 8
// 008fb4ac  c20400               ret 4
// standard library vector<pod48> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;

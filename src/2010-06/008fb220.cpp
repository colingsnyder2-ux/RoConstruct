// from server: 100% by auto
// roc 2010-06 008fb220  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fb220
//
// 008fb220  83ec08               sub esp, 8
// 008fb223  53                   push ebx
// 008fb224  56                   push esi
// 008fb225  8bf1                 mov esi, ecx
// 008fb227  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008fb22a  57                   push edi
// 008fb22b  85db                 test ebx, ebx
// 008fb22d  7504                 jne 0x8fb233
// 008fb22f  33c9                 xor ecx, ecx
// 008fb231  eb16                 jmp 0x8fb249
// 008fb233  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008fb236  2bcb                 sub ecx, ebx
// 008fb238  b8398ee338           mov eax, 0x38e38e39
// 008fb23d  f7e9                 imul ecx
// 008fb23f  c1fa03               sar edx, 3
// 008fb242  8bca                 mov ecx, edx
// 008fb244  c1e91f               shr ecx, 0x1f
// 008fb247  03ca                 add ecx, edx
// 008fb249  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008fb24c  8bd7                 mov edx, edi
// 008fb24e  2bd3                 sub edx, ebx
// 008fb250  b8398ee338           mov eax, 0x38e38e39
// 008fb255  f7ea                 imul edx
// 008fb257  c1fa03               sar edx, 3
// 008fb25a  8bc2                 mov eax, edx
// 008fb25c  c1e81f               shr eax, 0x1f
// 008fb25f  03c2                 add eax, edx
// 008fb261  3bc1                 cmp eax, ecx
// 008fb263  7332                 jae 0x8fb297
// 008fb265  8b542418             mov edx, dword ptr [esp + 0x18]
// 008fb269  c644240c00           mov byte ptr [esp + 0xc], 0
// 008fb26e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008fb272  51                   push ecx
// 008fb273  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008fb277  52                   push edx
// 008fb278  8d4608               lea eax, [esi + 8]
// 008fb27b  50                   push eax
// 008fb27c  51                   push ecx
// 008fb27d  6a01                 push 1
// 008fb27f  57                   push edi
// 008fb280  e8db75ffff           call 0x8f2860
// 008fb285  83c418               add esp, 0x18
// 008fb288  83c724               add edi, 0x24
// 008fb28b  897e10               mov dword ptr [esi + 0x10], edi
// 008fb28e  5f                   pop edi
// 008fb28f  5e                   pop esi
// 008fb290  5b                   pop ebx
// 008fb291  83c408               add esp, 8
// 008fb294  c20400               ret 4
// 008fb297  3bdf                 cmp ebx, edi
// 008fb299  7606                 jbe 0x8fb2a1
// 008fb29b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fb2a1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008fb2a5  8b06                 mov eax, dword ptr [esi]
// 008fb2a7  52                   push edx
// 008fb2a8  57                   push edi
// 008fb2a9  50                   push eax
// 008fb2aa  8d442418             lea eax, [esp + 0x18]
// 008fb2ae  50                   push eax
// 008fb2af  8bce                 mov ecx, esi
// 008fb2b1  e84af7ffff           call 0x8faa00
// 008fb2b6  5f                   pop edi
// 008fb2b7  5e                   pop esi
// 008fb2b8  5b                   pop ebx
// 008fb2b9  83c408               add esp, 8
// 008fb2bc  c20400               ret 4
// standard library vector<pod36> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;

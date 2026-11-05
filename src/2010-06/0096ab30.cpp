// from server: 100% by auto
// roc 2010-06 0096ab30  unit: Ogre::RbxSceneUpdater  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096ab30
//
// 0096ab30  83ec08               sub esp, 8
// 0096ab33  53                   push ebx
// 0096ab34  56                   push esi
// 0096ab35  8bf1                 mov esi, ecx
// 0096ab37  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096ab3a  57                   push edi
// 0096ab3b  85db                 test ebx, ebx
// 0096ab3d  7504                 jne 0x96ab43
// 0096ab3f  33c9                 xor ecx, ecx
// 0096ab41  eb16                 jmp 0x96ab59
// 0096ab43  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0096ab46  2bcb                 sub ecx, ebx
// 0096ab48  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096ab4d  f7e9                 imul ecx
// 0096ab4f  c1fa02               sar edx, 2
// 0096ab52  8bca                 mov ecx, edx
// 0096ab54  c1e91f               shr ecx, 0x1f
// 0096ab57  03ca                 add ecx, edx
// 0096ab59  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0096ab5c  8bd7                 mov edx, edi
// 0096ab5e  2bd3                 sub edx, ebx
// 0096ab60  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096ab65  f7ea                 imul edx
// 0096ab67  c1fa02               sar edx, 2
// 0096ab6a  8bc2                 mov eax, edx
// 0096ab6c  c1e81f               shr eax, 0x1f
// 0096ab6f  03c2                 add eax, edx
// 0096ab71  3bc1                 cmp eax, ecx
// 0096ab73  7332                 jae 0x96aba7
// 0096ab75  8b542418             mov edx, dword ptr [esp + 0x18]
// 0096ab79  c644240c00           mov byte ptr [esp + 0xc], 0
// 0096ab7e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0096ab82  51                   push ecx
// 0096ab83  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0096ab87  52                   push edx
// 0096ab88  8d4608               lea eax, [esi + 8]
// 0096ab8b  50                   push eax
// 0096ab8c  51                   push ecx
// 0096ab8d  6a01                 push 1
// 0096ab8f  57                   push edi
// 0096ab90  e8bbf9ffff           call 0x96a550
// 0096ab95  83c418               add esp, 0x18
// 0096ab98  83c718               add edi, 0x18
// 0096ab9b  897e10               mov dword ptr [esi + 0x10], edi
// 0096ab9e  5f                   pop edi
// 0096ab9f  5e                   pop esi
// 0096aba0  5b                   pop ebx
// 0096aba1  83c408               add esp, 8
// 0096aba4  c20400               ret 4
// 0096aba7  3bdf                 cmp ebx, edi
// 0096aba9  7606                 jbe 0x96abb1
// 0096abab  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096abb1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0096abb5  8b06                 mov eax, dword ptr [esi]
// 0096abb7  52                   push edx
// 0096abb8  57                   push edi
// 0096abb9  50                   push eax
// 0096abba  8d442418             lea eax, [esp + 0x18]
// 0096abbe  50                   push eax
// 0096abbf  8bce                 mov ecx, esi
// 0096abc1  e8bafeffff           call 0x96aa80
// 0096abc6  5f                   pop edi
// 0096abc7  5e                   pop esi
// 0096abc8  5b                   pop ebx
// 0096abc9  83c408               add esp, 8
// 0096abcc  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;

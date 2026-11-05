// from server: 100% by auto
// roc 2008-06 0069af50  unit: Ogre::InstancedGeometry  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069af50
//
// 0069af50  83ec08               sub esp, 8
// 0069af53  53                   push ebx
// 0069af54  56                   push esi
// 0069af55  8bf1                 mov esi, ecx
// 0069af57  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0069af5a  57                   push edi
// 0069af5b  85db                 test ebx, ebx
// 0069af5d  7504                 jne 0x69af63
// 0069af5f  33c9                 xor ecx, ecx
// 0069af61  eb16                 jmp 0x69af79
// 0069af63  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0069af66  2bcb                 sub ecx, ebx
// 0069af68  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0069af6d  f7e9                 imul ecx
// 0069af6f  c1fa02               sar edx, 2
// 0069af72  8bca                 mov ecx, edx
// 0069af74  c1e91f               shr ecx, 0x1f
// 0069af77  03ca                 add ecx, edx
// 0069af79  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0069af7c  8bd7                 mov edx, edi
// 0069af7e  2bd3                 sub edx, ebx
// 0069af80  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0069af85  f7ea                 imul edx
// 0069af87  c1fa02               sar edx, 2
// 0069af8a  8bc2                 mov eax, edx
// 0069af8c  c1e81f               shr eax, 0x1f
// 0069af8f  03c2                 add eax, edx
// 0069af91  3bc1                 cmp eax, ecx
// 0069af93  7332                 jae 0x69afc7
// 0069af95  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069af99  c644240c00           mov byte ptr [esp + 0xc], 0
// 0069af9e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069afa2  51                   push ecx
// 0069afa3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0069afa7  52                   push edx
// 0069afa8  8d4608               lea eax, [esi + 8]
// 0069afab  50                   push eax
// 0069afac  51                   push ecx
// 0069afad  6a01                 push 1
// 0069afaf  57                   push edi
// 0069afb0  e89b52ffff           call 0x690250
// 0069afb5  83c418               add esp, 0x18
// 0069afb8  83c718               add edi, 0x18
// 0069afbb  897e10               mov dword ptr [esi + 0x10], edi
// 0069afbe  5f                   pop edi
// 0069afbf  5e                   pop esi
// 0069afc0  5b                   pop ebx
// 0069afc1  83c408               add esp, 8
// 0069afc4  c20400               ret 4
// 0069afc7  3bdf                 cmp ebx, edi
// 0069afc9  7606                 jbe 0x69afd1
// 0069afcb  ff1590288000         call dword ptr [0x802890]
// 0069afd1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069afd5  8b06                 mov eax, dword ptr [esi]
// 0069afd7  52                   push edx
// 0069afd8  57                   push edi
// 0069afd9  50                   push eax
// 0069afda  8d442418             lea eax, [esp + 0x18]
// 0069afde  50                   push eax
// 0069afdf  8bce                 mov ecx, esi
// 0069afe1  e8caebffff           call 0x699bb0
// 0069afe6  5f                   pop edi
// 0069afe7  5e                   pop esi
// 0069afe8  5b                   pop ebx
// 0069afe9  83c408               add esp, 8
// 0069afec  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;

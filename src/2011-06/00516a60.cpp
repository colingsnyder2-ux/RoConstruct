// from server: 100% by auto
// roc 2011-06 00516a60  unit: RBX::Network::NetworkOwnerJob  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00516a60
//
// 00516a60  55                   push ebp
// 00516a61  8bec                 mov ebp, esp
// 00516a63  6aff                 push -1
// 00516a65  6871da9d00           push 0x9dda71
// 00516a6a  64a100000000         mov eax, dword ptr fs:[0]
// 00516a70  50                   push eax
// 00516a71  64892500000000       mov dword ptr fs:[0], esp
// 00516a78  83ec0c               sub esp, 0xc
// 00516a7b  53                   push ebx
// 00516a7c  56                   push esi
// 00516a7d  57                   push edi
// 00516a7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00516a81  6a30                 push 0x30
// 00516a83  e8d6352f00           call 0x80a05e
// 00516a88  8bf0                 mov esi, eax
// 00516a8a  83c404               add esp, 4
// 00516a8d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00516a90  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00516a97  8975e8               mov dword ptr [ebp - 0x18], esi
// 00516a9a  c645fc01             mov byte ptr [ebp - 4], 1
// 00516a9e  85f6                 test esi, esi
// 00516aa0  7430                 je 0x516ad2
// 00516aa2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00516aa5  8b4508               mov eax, dword ptr [ebp + 8]
// 00516aa8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00516aab  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 00516aae  894e04               mov dword ptr [esi + 4], ecx
// 00516ab1  8d7e0c               lea edi, [esi + 0xc]
// 00516ab4  53                   push ebx
// 00516ab5  8bcf                 mov ecx, edi
// 00516ab7  8906                 mov dword ptr [esi], eax
// 00516ab9  895608               mov dword ptr [esi + 8], edx
// 00516abc  ff15c804a400         call dword ptr [0xa404c8]
// 00516ac2  8a431c               mov al, byte ptr [ebx + 0x1c]
// 00516ac5  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00516ac8  88471c               mov byte ptr [edi + 0x1c], al
// 00516acb  884e2c               mov byte ptr [esi + 0x2c], cl
// 00516ace  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00516ad2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00516ad5  5f                   pop edi
// 00516ad6  8bc6                 mov eax, esi
// 00516ad8  5e                   pop esi
// 00516ad9  64890d00000000       mov dword ptr fs:[0], ecx
// 00516ae0  5b                   pop ebx
// 00516ae1  8be5                 mov esp, ebp
// 00516ae3  5d                   pop ebp
// 00516ae4  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;

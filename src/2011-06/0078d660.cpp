// from server: 100% by auto
// roc 2011-06 0078d660  unit: RBX::UniversalTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078d660
//
// 0078d660  55                   push ebp
// 0078d661  8bec                 mov ebp, esp
// 0078d663  6aff                 push -1
// 0078d665  68c1c49f00           push 0x9fc4c1
// 0078d66a  64a100000000         mov eax, dword ptr fs:[0]
// 0078d670  50                   push eax
// 0078d671  64892500000000       mov dword ptr fs:[0], esp
// 0078d678  83ec0c               sub esp, 0xc
// 0078d67b  53                   push ebx
// 0078d67c  56                   push esi
// 0078d67d  57                   push edi
// 0078d67e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0078d681  6a30                 push 0x30
// 0078d683  e8d6c90700           call 0x80a05e
// 0078d688  8bf0                 mov esi, eax
// 0078d68a  83c404               add esp, 4
// 0078d68d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0078d690  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0078d697  8975e8               mov dword ptr [ebp - 0x18], esi
// 0078d69a  c645fc01             mov byte ptr [ebp - 4], 1
// 0078d69e  85f6                 test esi, esi
// 0078d6a0  7430                 je 0x78d6d2
// 0078d6a2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0078d6a5  8b4508               mov eax, dword ptr [ebp + 8]
// 0078d6a8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0078d6ab  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0078d6ae  894e04               mov dword ptr [esi + 4], ecx
// 0078d6b1  8d7e0c               lea edi, [esi + 0xc]
// 0078d6b4  53                   push ebx
// 0078d6b5  8bcf                 mov ecx, edi
// 0078d6b7  8906                 mov dword ptr [esi], eax
// 0078d6b9  895608               mov dword ptr [esi + 8], edx
// 0078d6bc  ff15c804a400         call dword ptr [0xa404c8]
// 0078d6c2  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0078d6c5  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0078d6c8  89471c               mov dword ptr [edi + 0x1c], eax
// 0078d6cb  884e2c               mov byte ptr [esi + 0x2c], cl
// 0078d6ce  c6462d00             mov byte ptr [esi + 0x2d], 0
// 0078d6d2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0078d6d5  5f                   pop edi
// 0078d6d6  8bc6                 mov eax, esi
// 0078d6d8  5e                   pop esi
// 0078d6d9  64890d00000000       mov dword ptr fs:[0], ecx
// 0078d6e0  5b                   pop ebx
// 0078d6e1  8be5                 mov esp, ebp
// 0078d6e3  5d                   pop ebp
// 0078d6e4  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

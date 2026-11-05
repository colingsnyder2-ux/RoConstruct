// from server: 100% by auto
// roc 2007-08 005daa90  unit: RBX::VHole::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005daa90
//
// 005daa90  55                   push ebp
// 005daa91  8bec                 mov ebp, esp
// 005daa93  6aff                 push -1
// 005daa95  6881a67500           push 0x75a681
// 005daa9a  64a100000000         mov eax, dword ptr fs:[0]
// 005daaa0  50                   push eax
// 005daaa1  64892500000000       mov dword ptr fs:[0], esp
// 005daaa8  83ec0c               sub esp, 0xc
// 005daaab  53                   push ebx
// 005daaac  56                   push esi
// 005daaad  57                   push edi
// 005daaae  8965f0               mov dword ptr [ebp - 0x10], esp
// 005daab1  6a30                 push 0x30
// 005daab3  e83e540500           call 0x62fef6
// 005daab8  8bf0                 mov esi, eax
// 005daaba  83c404               add esp, 4
// 005daabd  8975ec               mov dword ptr [ebp - 0x14], esi
// 005daac0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005daac7  8975e8               mov dword ptr [ebp - 0x18], esi
// 005daaca  85f6                 test esi, esi
// 005daacc  c645fc01             mov byte ptr [ebp - 4], 1
// 005daad0  7430                 je 0x5dab02
// 005daad2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005daad5  8b4508               mov eax, dword ptr [ebp + 8]
// 005daad8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005daadb  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 005daade  894e04               mov dword ptr [esi + 4], ecx
// 005daae1  8d7e0c               lea edi, [esi + 0xc]
// 005daae4  53                   push ebx
// 005daae5  8bcf                 mov ecx, edi
// 005daae7  8906                 mov dword ptr [esi], eax
// 005daae9  895608               mov dword ptr [esi + 8], edx
// 005daaec  ff159ce67700         call dword ptr [0x77e69c]
// 005daaf2  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 005daaf5  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 005daaf8  89471c               mov dword ptr [edi + 0x1c], eax
// 005daafb  884e2c               mov byte ptr [esi + 0x2c], cl
// 005daafe  c6462d00             mov byte ptr [esi + 0x2d], 0
// 005dab02  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005dab05  5f                   pop edi
// 005dab06  8bc6                 mov eax, esi
// 005dab08  5e                   pop esi
// 005dab09  64890d00000000       mov dword ptr fs:[0], ecx
// 005dab10  5b                   pop ebx
// 005dab11  8be5                 mov esp, ebp
// 005dab13  5d                   pop ebp
// 005dab14  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

// from server: 100% by auto
// roc 2007-08 00445630  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445630
//
// 00445630  55                   push ebp
// 00445631  8bec                 mov ebp, esp
// 00445633  6aff                 push -1
// 00445635  6811f67300           push 0x73f611
// 0044563a  64a100000000         mov eax, dword ptr fs:[0]
// 00445640  50                   push eax
// 00445641  83ec0c               sub esp, 0xc
// 00445644  53                   push ebx
// 00445645  56                   push esi
// 00445646  57                   push edi
// 00445647  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044564c  33c5                 xor eax, ebp
// 0044564e  50                   push eax
// 0044564f  8d45f4               lea eax, [ebp - 0xc]
// 00445652  64a300000000         mov dword ptr fs:[0], eax
// 00445658  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044565b  6a30                 push 0x30
// 0044565d  e894a81e00           call 0x62fef6
// 00445662  8bf0                 mov esi, eax
// 00445664  83c404               add esp, 4
// 00445667  8975ec               mov dword ptr [ebp - 0x14], esi
// 0044566a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00445671  8975e8               mov dword ptr [ebp - 0x18], esi
// 00445674  85f6                 test esi, esi
// 00445676  c645fc01             mov byte ptr [ebp - 4], 1
// 0044567a  7430                 je 0x4456ac
// 0044567c  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0044567f  8b4508               mov eax, dword ptr [ebp + 8]
// 00445682  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00445685  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 00445688  894e04               mov dword ptr [esi + 4], ecx
// 0044568b  8d7e0c               lea edi, [esi + 0xc]
// 0044568e  53                   push ebx
// 0044568f  8bcf                 mov ecx, edi
// 00445691  8906                 mov dword ptr [esi], eax
// 00445693  895608               mov dword ptr [esi + 8], edx
// 00445696  ff159ce67700         call dword ptr [0x77e69c]
// 0044569c  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0044569f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004456a2  89471c               mov dword ptr [edi + 0x1c], eax
// 004456a5  884e2c               mov byte ptr [esi + 0x2c], cl
// 004456a8  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004456ac  8bc6                 mov eax, esi
// 004456ae  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004456b1  64890d00000000       mov dword ptr fs:[0], ecx
// 004456b8  59                   pop ecx
// 004456b9  5f                   pop edi
// 004456ba  5e                   pop esi
// 004456bb  5b                   pop ebx
// 004456bc  8be5                 mov esp, ebp
// 004456be  5d                   pop ebp
// 004456bf  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

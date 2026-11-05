// from server: 100% by auto
// roc 2009-12 0047aa40  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047aa40
//
// 0047aa40  55                   push ebp
// 0047aa41  8bec                 mov ebp, esp
// 0047aa43  6aff                 push -1
// 0047aa45  6891e59200           push 0x92e591
// 0047aa4a  64a100000000         mov eax, dword ptr fs:[0]
// 0047aa50  50                   push eax
// 0047aa51  64892500000000       mov dword ptr fs:[0], esp
// 0047aa58  83ec0c               sub esp, 0xc
// 0047aa5b  53                   push ebx
// 0047aa5c  56                   push esi
// 0047aa5d  57                   push edi
// 0047aa5e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0047aa61  6a30                 push 0x30
// 0047aa63  e8f88d3700           call 0x7f3860
// 0047aa68  8bf0                 mov esi, eax
// 0047aa6a  83c404               add esp, 4
// 0047aa6d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0047aa70  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0047aa77  8975e8               mov dword ptr [ebp - 0x18], esi
// 0047aa7a  c645fc01             mov byte ptr [ebp - 4], 1
// 0047aa7e  85f6                 test esi, esi
// 0047aa80  7430                 je 0x47aab2
// 0047aa82  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0047aa85  8b4508               mov eax, dword ptr [ebp + 8]
// 0047aa88  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0047aa8b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0047aa8e  894e04               mov dword ptr [esi + 4], ecx
// 0047aa91  8d7e0c               lea edi, [esi + 0xc]
// 0047aa94  53                   push ebx
// 0047aa95  8bcf                 mov ecx, edi
// 0047aa97  8906                 mov dword ptr [esi], eax
// 0047aa99  895608               mov dword ptr [esi + 8], edx
// 0047aa9c  ff15f0b69800         call dword ptr [0x98b6f0]
// 0047aaa2  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0047aaa5  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0047aaa8  89471c               mov dword ptr [edi + 0x1c], eax
// 0047aaab  884e2c               mov byte ptr [esi + 0x2c], cl
// 0047aaae  c6462d00             mov byte ptr [esi + 0x2d], 0
// 0047aab2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0047aab5  5f                   pop edi
// 0047aab6  8bc6                 mov eax, esi
// 0047aab8  5e                   pop esi
// 0047aab9  64890d00000000       mov dword ptr fs:[0], ecx
// 0047aac0  5b                   pop ebx
// 0047aac1  8be5                 mov esp, ebp
// 0047aac3  5d                   pop ebp
// 0047aac4  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

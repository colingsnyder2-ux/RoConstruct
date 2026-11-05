// from server: 100% by auto
// roc 2012-06 008b13a0  unit: RBX::PluginMouse  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b13a0
//
// 008b13a0  55                   push ebp
// 008b13a1  8bec                 mov ebp, esp
// 008b13a3  6aff                 push -1
// 008b13a5  683134ad00           push 0xad3431
// 008b13aa  64a100000000         mov eax, dword ptr fs:[0]
// 008b13b0  50                   push eax
// 008b13b1  64892500000000       mov dword ptr fs:[0], esp
// 008b13b8  83ec0c               sub esp, 0xc
// 008b13bb  53                   push ebx
// 008b13bc  56                   push esi
// 008b13bd  57                   push edi
// 008b13be  8965f0               mov dword ptr [ebp - 0x10], esp
// 008b13c1  6a30                 push 0x30
// 008b13c3  e8520d0d00           call 0x98211a
// 008b13c8  8bf0                 mov esi, eax
// 008b13ca  83c404               add esp, 4
// 008b13cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 008b13d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008b13d7  8975e8               mov dword ptr [ebp - 0x18], esi
// 008b13da  c645fc01             mov byte ptr [ebp - 4], 1
// 008b13de  85f6                 test esi, esi
// 008b13e0  7430                 je 0x8b1412
// 008b13e2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 008b13e5  8b4508               mov eax, dword ptr [ebp + 8]
// 008b13e8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008b13eb  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 008b13ee  894e04               mov dword ptr [esi + 4], ecx
// 008b13f1  8d7e0c               lea edi, [esi + 0xc]
// 008b13f4  53                   push ebx
// 008b13f5  8bcf                 mov ecx, edi
// 008b13f7  8906                 mov dword ptr [esi], eax
// 008b13f9  895608               mov dword ptr [esi + 8], edx
// 008b13fc  ff154426b200         call dword ptr [0xb22644]
// 008b1402  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 008b1405  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 008b1408  89471c               mov dword ptr [edi + 0x1c], eax
// 008b140b  884e2c               mov byte ptr [esi + 0x2c], cl
// 008b140e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 008b1412  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008b1415  5f                   pop edi
// 008b1416  8bc6                 mov eax, esi
// 008b1418  5e                   pop esi
// 008b1419  64890d00000000       mov dword ptr fs:[0], ecx
// 008b1420  5b                   pop ebx
// 008b1421  8be5                 mov esp, ebp
// 008b1423  5d                   pop ebp
// 008b1424  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;

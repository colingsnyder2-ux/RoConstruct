// from server: 100% by auto
// roc 2012-06 00693f70  unit: RBX::VStockSound::?$FactoryProduct  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00693f70
//
// 00693f70  55                   push ebp
// 00693f71  8bec                 mov ebp, esp
// 00693f73  6aff                 push -1
// 00693f75  68216bab00           push 0xab6b21
// 00693f7a  64a100000000         mov eax, dword ptr fs:[0]
// 00693f80  50                   push eax
// 00693f81  64892500000000       mov dword ptr fs:[0], esp
// 00693f88  83ec0c               sub esp, 0xc
// 00693f8b  53                   push ebx
// 00693f8c  56                   push esi
// 00693f8d  57                   push edi
// 00693f8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00693f91  6a38                 push 0x38
// 00693f93  e882e12e00           call 0x98211a
// 00693f98  8bf0                 mov esi, eax
// 00693f9a  83c404               add esp, 4
// 00693f9d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00693fa0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00693fa7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00693faa  c645fc01             mov byte ptr [ebp - 4], 1
// 00693fae  85f6                 test esi, esi
// 00693fb0  741b                 je 0x693fcd
// 00693fb2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00693fb5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00693fb8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00693fbb  50                   push eax
// 00693fbc  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00693fbf  51                   push ecx
// 00693fc0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00693fc3  52                   push edx
// 00693fc4  50                   push eax
// 00693fc5  51                   push ecx
// 00693fc6  8bce                 mov ecx, esi
// 00693fc8  e8d3f5ffff           call 0x6935a0
// 00693fcd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00693fd0  5f                   pop edi
// 00693fd1  8bc6                 mov eax, esi
// 00693fd3  5e                   pop esi
// 00693fd4  64890d00000000       mov dword ptr fs:[0], ecx
// 00693fdb  5b                   pop ebx
// 00693fdc  8be5                 mov esp, ebp
// 00693fde  5d                   pop ebp
// 00693fdf  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

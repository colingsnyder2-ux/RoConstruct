// from server: 100% by auto
// roc 2009-06 004fbba0  unit: RBX::Network::ServerReplicator  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fbba0
//
// 004fbba0  55                   push ebp
// 004fbba1  8bec                 mov ebp, esp
// 004fbba3  6aff                 push -1
// 004fbba5  6861d18500           push 0x85d161
// 004fbbaa  64a100000000         mov eax, dword ptr fs:[0]
// 004fbbb0  50                   push eax
// 004fbbb1  64892500000000       mov dword ptr fs:[0], esp
// 004fbbb8  83ec0c               sub esp, 0xc
// 004fbbbb  53                   push ebx
// 004fbbbc  56                   push esi
// 004fbbbd  57                   push edi
// 004fbbbe  8965f0               mov dword ptr [ebp - 0x10], esp
// 004fbbc1  6a3c                 push 0x3c
// 004fbbc3  e870ce2100           call 0x718a38
// 004fbbc8  8bf0                 mov esi, eax
// 004fbbca  83c404               add esp, 4
// 004fbbcd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004fbbd0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004fbbd7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004fbbda  c645fc01             mov byte ptr [ebp - 4], 1
// 004fbbde  85f6                 test esi, esi
// 004fbbe0  741b                 je 0x4fbbfd
// 004fbbe2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004fbbe5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004fbbe8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004fbbeb  50                   push eax
// 004fbbec  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004fbbef  51                   push ecx
// 004fbbf0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004fbbf3  52                   push edx
// 004fbbf4  50                   push eax
// 004fbbf5  51                   push ecx
// 004fbbf6  8bce                 mov ecx, esi
// 004fbbf8  e843ffffff           call 0x4fbb40
// 004fbbfd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004fbc00  5f                   pop edi
// 004fbc01  8bc6                 mov eax, esi
// 004fbc03  5e                   pop esi
// 004fbc04  64890d00000000       mov dword ptr fs:[0], ecx
// 004fbc0b  5b                   pop ebx
// 004fbc0c  8be5                 mov esp, ebp
// 004fbc0e  5d                   pop ebp
// 004fbc0f  c21400               ret 0x14
// standard library map_str<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

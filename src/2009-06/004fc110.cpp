// from server: 100% by auto
// roc 2009-06 004fc110  unit: RBX::Network::ServerReplicator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fc110
//
// 004fc110  53                   push ebx
// 004fc111  56                   push esi
// 004fc112  57                   push edi
// 004fc113  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004fc117  807f3900             cmp byte ptr [edi + 0x39], 0
// 004fc11b  8bd9                 mov ebx, ecx
// 004fc11d  8bf7                 mov esi, edi
// 004fc11f  7527                 jne 0x4fc148
// 004fc121  8b4608               mov eax, dword ptr [esi + 8]
// 004fc124  50                   push eax
// 004fc125  8bcb                 mov ecx, ebx
// 004fc127  e8e4ffffff           call 0x4fc110
// 004fc12c  8b36                 mov esi, dword ptr [esi]
// 004fc12e  8d4f0c               lea ecx, [edi + 0xc]
// 004fc131  ff15c4e48900         call dword ptr [0x89e4c4]
// 004fc137  57                   push edi
// 004fc138  e8f5c82100           call 0x718a32
// 004fc13d  83c404               add esp, 4
// 004fc140  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fc144  8bfe                 mov edi, esi
// 004fc146  74d9                 je 0x4fc121
// 004fc148  5f                   pop edi
// 004fc149  5e                   pop esi
// 004fc14a  5b                   pop ebx
// 004fc14b  c20400               ret 4
// standard library map_str<pod16> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

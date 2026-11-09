// from server: 100% by auto
// roc 2009-06 004fba50  unit: RBX::Network::ServerReplicator  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fba50
//
// 004fba50  8b542404             mov edx, dword ptr [esp + 4]
// 004fba54  8b02                 mov eax, dword ptr [edx]
// 004fba56  56                   push esi
// 004fba57  8b7008               mov esi, dword ptr [eax + 8]
// 004fba5a  8932                 mov dword ptr [edx], esi
// 004fba5c  8b7008               mov esi, dword ptr [eax + 8]
// 004fba5f  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fba63  7503                 jne 0x4fba68
// 004fba65  895604               mov dword ptr [esi + 4], edx
// 004fba68  8b7204               mov esi, dword ptr [edx + 4]
// 004fba6b  897004               mov dword ptr [eax + 4], esi
// 004fba6e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004fba71  5e                   pop esi
// 004fba72  3b5104               cmp edx, dword ptr [ecx + 4]
// 004fba75  750c                 jne 0x4fba83
// 004fba77  894104               mov dword ptr [ecx + 4], eax
// 004fba7a  895008               mov dword ptr [eax + 8], edx
// 004fba7d  894204               mov dword ptr [edx + 4], eax
// 004fba80  c20400               ret 4
// 004fba83  8b4a04               mov ecx, dword ptr [edx + 4]
// 004fba86  3b5108               cmp edx, dword ptr [ecx + 8]
// 004fba89  750c                 jne 0x4fba97
// 004fba8b  894108               mov dword ptr [ecx + 8], eax
// 004fba8e  895008               mov dword ptr [eax + 8], edx
// 004fba91  894204               mov dword ptr [edx + 4], eax
// 004fba94  c20400               ret 4
// 004fba97  8901                 mov dword ptr [ecx], eax
// 004fba99  895008               mov dword ptr [eax + 8], edx
// 004fba9c  894204               mov dword ptr [edx + 4], eax
// 004fba9f  c20400               ret 4
// standard library map_int<pod40> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

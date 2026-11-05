// from server: 100% by auto
// roc 2009-06 004fba00  unit: RBX::Network::ServerReplicator  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fba00
//
// 004fba00  8b542404             mov edx, dword ptr [esp + 4]
// 004fba04  8b4208               mov eax, dword ptr [edx + 8]
// 004fba07  56                   push esi
// 004fba08  8b30                 mov esi, dword ptr [eax]
// 004fba0a  897208               mov dword ptr [edx + 8], esi
// 004fba0d  8b30                 mov esi, dword ptr [eax]
// 004fba0f  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fba13  7503                 jne 0x4fba18
// 004fba15  895604               mov dword ptr [esi + 4], edx
// 004fba18  8b7204               mov esi, dword ptr [edx + 4]
// 004fba1b  897004               mov dword ptr [eax + 4], esi
// 004fba1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004fba21  5e                   pop esi
// 004fba22  3b5104               cmp edx, dword ptr [ecx + 4]
// 004fba25  750b                 jne 0x4fba32
// 004fba27  894104               mov dword ptr [ecx + 4], eax
// 004fba2a  8910                 mov dword ptr [eax], edx
// 004fba2c  894204               mov dword ptr [edx + 4], eax
// 004fba2f  c20400               ret 4
// 004fba32  8b4a04               mov ecx, dword ptr [edx + 4]
// 004fba35  3b11                 cmp edx, dword ptr [ecx]
// 004fba37  750a                 jne 0x4fba43
// 004fba39  8901                 mov dword ptr [ecx], eax
// 004fba3b  8910                 mov dword ptr [eax], edx
// 004fba3d  894204               mov dword ptr [edx + 4], eax
// 004fba40  c20400               ret 4
// 004fba43  894108               mov dword ptr [ecx + 8], eax
// 004fba46  8910                 mov dword ptr [eax], edx
// 004fba48  894204               mov dword ptr [edx + 4], eax
// 004fba4b  c20400               ret 4
// standard library map_int<pod40> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

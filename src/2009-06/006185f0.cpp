// from server: 100% by auto
// roc 2009-06 006185f0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006185f0
//
// 006185f0  8b542404             mov edx, dword ptr [esp + 4]
// 006185f4  8b4208               mov eax, dword ptr [edx + 8]
// 006185f7  56                   push esi
// 006185f8  8b30                 mov esi, dword ptr [eax]
// 006185fa  897208               mov dword ptr [edx + 8], esi
// 006185fd  8b30                 mov esi, dword ptr [eax]
// 006185ff  807e4900             cmp byte ptr [esi + 0x49], 0
// 00618603  7503                 jne 0x618608
// 00618605  895604               mov dword ptr [esi + 4], edx
// 00618608  8b7204               mov esi, dword ptr [edx + 4]
// 0061860b  897004               mov dword ptr [eax + 4], esi
// 0061860e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00618611  5e                   pop esi
// 00618612  3b5104               cmp edx, dword ptr [ecx + 4]
// 00618615  750b                 jne 0x618622
// 00618617  894104               mov dword ptr [ecx + 4], eax
// 0061861a  8910                 mov dword ptr [eax], edx
// 0061861c  894204               mov dword ptr [edx + 4], eax
// 0061861f  c20400               ret 4
// 00618622  8b4a04               mov ecx, dword ptr [edx + 4]
// 00618625  3b11                 cmp edx, dword ptr [ecx]
// 00618627  750a                 jne 0x618633
// 00618629  8901                 mov dword ptr [ecx], eax
// 0061862b  8910                 mov dword ptr [eax], edx
// 0061862d  894204               mov dword ptr [edx + 4], eax
// 00618630  c20400               ret 4
// 00618633  894108               mov dword ptr [ecx + 8], eax
// 00618636  8910                 mov dword ptr [eax], edx
// 00618638  894204               mov dword ptr [edx + 4], eax
// 0061863b  c20400               ret 4
// standard library map_str<pod32> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

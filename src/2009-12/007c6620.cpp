// from server: 100% by auto
// roc 2009-12 007c6620  unit: RBX::ScoreHud  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6620
//
// 007c6620  8b542404             mov edx, dword ptr [esp + 4]
// 007c6624  8b4208               mov eax, dword ptr [edx + 8]
// 007c6627  56                   push esi
// 007c6628  8b30                 mov esi, dword ptr [eax]
// 007c662a  897208               mov dword ptr [edx + 8], esi
// 007c662d  8b30                 mov esi, dword ptr [eax]
// 007c662f  807e4900             cmp byte ptr [esi + 0x49], 0
// 007c6633  7503                 jne 0x7c6638
// 007c6635  895604               mov dword ptr [esi + 4], edx
// 007c6638  8b7204               mov esi, dword ptr [edx + 4]
// 007c663b  897004               mov dword ptr [eax + 4], esi
// 007c663e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007c6641  5e                   pop esi
// 007c6642  3b5104               cmp edx, dword ptr [ecx + 4]
// 007c6645  750b                 jne 0x7c6652
// 007c6647  894104               mov dword ptr [ecx + 4], eax
// 007c664a  8910                 mov dword ptr [eax], edx
// 007c664c  894204               mov dword ptr [edx + 4], eax
// 007c664f  c20400               ret 4
// 007c6652  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c6655  3b11                 cmp edx, dword ptr [ecx]
// 007c6657  750a                 jne 0x7c6663
// 007c6659  8901                 mov dword ptr [ecx], eax
// 007c665b  8910                 mov dword ptr [eax], edx
// 007c665d  894204               mov dword ptr [edx + 4], eax
// 007c6660  c20400               ret 4
// 007c6663  894108               mov dword ptr [ecx + 8], eax
// 007c6666  8910                 mov dword ptr [eax], edx
// 007c6668  894204               mov dword ptr [edx + 4], eax
// 007c666b  c20400               ret 4
// standard library map_str<pod32> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

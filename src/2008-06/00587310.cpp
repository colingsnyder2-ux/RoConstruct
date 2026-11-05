// from server: 100% by auto
// roc 2008-06 00587310  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587310
//
// 00587310  8b542404             mov edx, dword ptr [esp + 4]
// 00587314  8b4208               mov eax, dword ptr [edx + 8]
// 00587317  56                   push esi
// 00587318  8b30                 mov esi, dword ptr [eax]
// 0058731a  897208               mov dword ptr [edx + 8], esi
// 0058731d  8b30                 mov esi, dword ptr [eax]
// 0058731f  807e4900             cmp byte ptr [esi + 0x49], 0
// 00587323  7503                 jne 0x587328
// 00587325  895604               mov dword ptr [esi + 4], edx
// 00587328  8b7204               mov esi, dword ptr [edx + 4]
// 0058732b  897004               mov dword ptr [eax + 4], esi
// 0058732e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00587331  5e                   pop esi
// 00587332  3b5104               cmp edx, dword ptr [ecx + 4]
// 00587335  750b                 jne 0x587342
// 00587337  894104               mov dword ptr [ecx + 4], eax
// 0058733a  8910                 mov dword ptr [eax], edx
// 0058733c  894204               mov dword ptr [edx + 4], eax
// 0058733f  c20400               ret 4
// 00587342  8b4a04               mov ecx, dword ptr [edx + 4]
// 00587345  3b11                 cmp edx, dword ptr [ecx]
// 00587347  750a                 jne 0x587353
// 00587349  8901                 mov dword ptr [ecx], eax
// 0058734b  8910                 mov dword ptr [eax], edx
// 0058734d  894204               mov dword ptr [edx + 4], eax
// 00587350  c20400               ret 4
// 00587353  894108               mov dword ptr [ecx + 8], eax
// 00587356  8910                 mov dword ptr [eax], edx
// 00587358  894204               mov dword ptr [edx + 4], eax
// 0058735b  c20400               ret 4
// standard library map_str<pod32> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

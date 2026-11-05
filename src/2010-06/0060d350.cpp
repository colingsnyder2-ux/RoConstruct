// from server: 100% by auto
// roc 2010-06 0060d350  unit: RBX::VScriptContext::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060d350
//
// 0060d350  8b542404             mov edx, dword ptr [esp + 4]
// 0060d354  8b4208               mov eax, dword ptr [edx + 8]
// 0060d357  56                   push esi
// 0060d358  8b30                 mov esi, dword ptr [eax]
// 0060d35a  897208               mov dword ptr [edx + 8], esi
// 0060d35d  8b30                 mov esi, dword ptr [eax]
// 0060d35f  807e4900             cmp byte ptr [esi + 0x49], 0
// 0060d363  7503                 jne 0x60d368
// 0060d365  895604               mov dword ptr [esi + 4], edx
// 0060d368  8b7204               mov esi, dword ptr [edx + 4]
// 0060d36b  897004               mov dword ptr [eax + 4], esi
// 0060d36e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0060d371  5e                   pop esi
// 0060d372  3b5104               cmp edx, dword ptr [ecx + 4]
// 0060d375  750b                 jne 0x60d382
// 0060d377  894104               mov dword ptr [ecx + 4], eax
// 0060d37a  8910                 mov dword ptr [eax], edx
// 0060d37c  894204               mov dword ptr [edx + 4], eax
// 0060d37f  c20400               ret 4
// 0060d382  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060d385  3b11                 cmp edx, dword ptr [ecx]
// 0060d387  750a                 jne 0x60d393
// 0060d389  8901                 mov dword ptr [ecx], eax
// 0060d38b  8910                 mov dword ptr [eax], edx
// 0060d38d  894204               mov dword ptr [edx + 4], eax
// 0060d390  c20400               ret 4
// 0060d393  894108               mov dword ptr [ecx + 8], eax
// 0060d396  8910                 mov dword ptr [eax], edx
// 0060d398  894204               mov dword ptr [edx + 4], eax
// 0060d39b  c20400               ret 4
// standard library map_str<pod32> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

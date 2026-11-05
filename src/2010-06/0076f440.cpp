// from server: 100% by auto
// roc 2010-06 0076f440  unit: RBX::ChatOutput  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f440
//
// 0076f440  8b542404             mov edx, dword ptr [esp + 4]
// 0076f444  8b02                 mov eax, dword ptr [edx]
// 0076f446  56                   push esi
// 0076f447  8b7008               mov esi, dword ptr [eax + 8]
// 0076f44a  8932                 mov dword ptr [edx], esi
// 0076f44c  8b7008               mov esi, dword ptr [eax + 8]
// 0076f44f  807e4900             cmp byte ptr [esi + 0x49], 0
// 0076f453  7503                 jne 0x76f458
// 0076f455  895604               mov dword ptr [esi + 4], edx
// 0076f458  8b7204               mov esi, dword ptr [edx + 4]
// 0076f45b  897004               mov dword ptr [eax + 4], esi
// 0076f45e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0076f461  5e                   pop esi
// 0076f462  3b5104               cmp edx, dword ptr [ecx + 4]
// 0076f465  750c                 jne 0x76f473
// 0076f467  894104               mov dword ptr [ecx + 4], eax
// 0076f46a  895008               mov dword ptr [eax + 8], edx
// 0076f46d  894204               mov dword ptr [edx + 4], eax
// 0076f470  c20400               ret 4
// 0076f473  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076f476  3b5108               cmp edx, dword ptr [ecx + 8]
// 0076f479  750c                 jne 0x76f487
// 0076f47b  894108               mov dword ptr [ecx + 8], eax
// 0076f47e  895008               mov dword ptr [eax + 8], edx
// 0076f481  894204               mov dword ptr [edx + 4], eax
// 0076f484  c20400               ret 4
// 0076f487  8901                 mov dword ptr [ecx], eax
// 0076f489  895008               mov dword ptr [eax + 8], edx
// 0076f48c  894204               mov dword ptr [edx + 4], eax
// 0076f48f  c20400               ret 4
// standard library map_str<pod32> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

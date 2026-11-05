// from server: 100% by auto
// roc 2009-06 00413ba0  unit: CutVerb  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413ba0
//
// 00413ba0  8b542404             mov edx, dword ptr [esp + 4]
// 00413ba4  8b02                 mov eax, dword ptr [edx]
// 00413ba6  56                   push esi
// 00413ba7  8b7008               mov esi, dword ptr [eax + 8]
// 00413baa  8932                 mov dword ptr [edx], esi
// 00413bac  8b7008               mov esi, dword ptr [eax + 8]
// 00413baf  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413bb3  7503                 jne 0x413bb8
// 00413bb5  895604               mov dword ptr [esi + 4], edx
// 00413bb8  8b7204               mov esi, dword ptr [edx + 4]
// 00413bbb  897004               mov dword ptr [eax + 4], esi
// 00413bbe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413bc1  5e                   pop esi
// 00413bc2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413bc5  750c                 jne 0x413bd3
// 00413bc7  894104               mov dword ptr [ecx + 4], eax
// 00413bca  895008               mov dword ptr [eax + 8], edx
// 00413bcd  894204               mov dword ptr [edx + 4], eax
// 00413bd0  c20400               ret 4
// 00413bd3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413bd6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00413bd9  750c                 jne 0x413be7
// 00413bdb  894108               mov dword ptr [ecx + 8], eax
// 00413bde  895008               mov dword ptr [eax + 8], edx
// 00413be1  894204               mov dword ptr [edx + 4], eax
// 00413be4  c20400               ret 4
// 00413be7  8901                 mov dword ptr [ecx], eax
// 00413be9  895008               mov dword ptr [eax + 8], edx
// 00413bec  894204               mov dword ptr [edx + 4], eax
// 00413bef  c20400               ret 4
// standard library map_str<string> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

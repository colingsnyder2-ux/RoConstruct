// from server: 100% by auto
// roc 2008-06 00413560  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413560
//
// 00413560  8b542404             mov edx, dword ptr [esp + 4]
// 00413564  8b4208               mov eax, dword ptr [edx + 8]
// 00413567  56                   push esi
// 00413568  8b30                 mov esi, dword ptr [eax]
// 0041356a  897208               mov dword ptr [edx + 8], esi
// 0041356d  8b30                 mov esi, dword ptr [eax]
// 0041356f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413573  7503                 jne 0x413578
// 00413575  895604               mov dword ptr [esi + 4], edx
// 00413578  8b7204               mov esi, dword ptr [edx + 4]
// 0041357b  897004               mov dword ptr [eax + 4], esi
// 0041357e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413581  5e                   pop esi
// 00413582  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413585  750b                 jne 0x413592
// 00413587  894104               mov dword ptr [ecx + 4], eax
// 0041358a  8910                 mov dword ptr [eax], edx
// 0041358c  894204               mov dword ptr [edx + 4], eax
// 0041358f  c20400               ret 4
// 00413592  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413595  3b11                 cmp edx, dword ptr [ecx]
// 00413597  750a                 jne 0x4135a3
// 00413599  8901                 mov dword ptr [ecx], eax
// 0041359b  8910                 mov dword ptr [eax], edx
// 0041359d  894204               mov dword ptr [edx + 4], eax
// 004135a0  c20400               ret 4
// 004135a3  894108               mov dword ptr [ecx + 8], eax
// 004135a6  8910                 mov dword ptr [eax], edx
// 004135a8  894204               mov dword ptr [edx + 4], eax
// 004135ab  c20400               ret 4
// standard library map_str<string> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

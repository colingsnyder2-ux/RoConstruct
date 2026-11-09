// from server: 100% by auto
// roc 2009-06 00413b10  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413b10
//
// 00413b10  8b542404             mov edx, dword ptr [esp + 4]
// 00413b14  8b4208               mov eax, dword ptr [edx + 8]
// 00413b17  56                   push esi
// 00413b18  8b30                 mov esi, dword ptr [eax]
// 00413b1a  897208               mov dword ptr [edx + 8], esi
// 00413b1d  8b30                 mov esi, dword ptr [eax]
// 00413b1f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413b23  7503                 jne 0x413b28
// 00413b25  895604               mov dword ptr [esi + 4], edx
// 00413b28  8b7204               mov esi, dword ptr [edx + 4]
// 00413b2b  897004               mov dword ptr [eax + 4], esi
// 00413b2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413b31  5e                   pop esi
// 00413b32  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413b35  750b                 jne 0x413b42
// 00413b37  894104               mov dword ptr [ecx + 4], eax
// 00413b3a  8910                 mov dword ptr [eax], edx
// 00413b3c  894204               mov dword ptr [edx + 4], eax
// 00413b3f  c20400               ret 4
// 00413b42  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413b45  3b11                 cmp edx, dword ptr [ecx]
// 00413b47  750a                 jne 0x413b53
// 00413b49  8901                 mov dword ptr [ecx], eax
// 00413b4b  8910                 mov dword ptr [eax], edx
// 00413b4d  894204               mov dword ptr [edx + 4], eax
// 00413b50  c20400               ret 4
// 00413b53  894108               mov dword ptr [ecx + 8], eax
// 00413b56  8910                 mov dword ptr [eax], edx
// 00413b58  894204               mov dword ptr [edx + 4], eax
// 00413b5b  c20400               ret 4
// standard library map_str<string> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

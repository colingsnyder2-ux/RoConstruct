// from server: 100% by auto
// roc 2009-12 00413580  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413580
//
// 00413580  8b542404             mov edx, dword ptr [esp + 4]
// 00413584  8b4208               mov eax, dword ptr [edx + 8]
// 00413587  56                   push esi
// 00413588  8b30                 mov esi, dword ptr [eax]
// 0041358a  897208               mov dword ptr [edx + 8], esi
// 0041358d  8b30                 mov esi, dword ptr [eax]
// 0041358f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413593  7503                 jne 0x413598
// 00413595  895604               mov dword ptr [esi + 4], edx
// 00413598  8b7204               mov esi, dword ptr [edx + 4]
// 0041359b  897004               mov dword ptr [eax + 4], esi
// 0041359e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004135a1  5e                   pop esi
// 004135a2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004135a5  750b                 jne 0x4135b2
// 004135a7  894104               mov dword ptr [ecx + 4], eax
// 004135aa  8910                 mov dword ptr [eax], edx
// 004135ac  894204               mov dword ptr [edx + 4], eax
// 004135af  c20400               ret 4
// 004135b2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004135b5  3b11                 cmp edx, dword ptr [ecx]
// 004135b7  750a                 jne 0x4135c3
// 004135b9  8901                 mov dword ptr [ecx], eax
// 004135bb  8910                 mov dword ptr [eax], edx
// 004135bd  894204               mov dword ptr [edx + 4], eax
// 004135c0  c20400               ret 4
// 004135c3  894108               mov dword ptr [ecx + 8], eax
// 004135c6  8910                 mov dword ptr [eax], edx
// 004135c8  894204               mov dword ptr [edx + 4], eax
// 004135cb  c20400               ret 4
// standard library map_str<string> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

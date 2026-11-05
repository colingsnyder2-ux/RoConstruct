// from server: 100% by auto
// roc 2010-06 00413850  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413850
//
// 00413850  8b542404             mov edx, dword ptr [esp + 4]
// 00413854  8b4208               mov eax, dword ptr [edx + 8]
// 00413857  56                   push esi
// 00413858  8b30                 mov esi, dword ptr [eax]
// 0041385a  897208               mov dword ptr [edx + 8], esi
// 0041385d  8b30                 mov esi, dword ptr [eax]
// 0041385f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413863  7503                 jne 0x413868
// 00413865  895604               mov dword ptr [esi + 4], edx
// 00413868  8b7204               mov esi, dword ptr [edx + 4]
// 0041386b  897004               mov dword ptr [eax + 4], esi
// 0041386e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413871  5e                   pop esi
// 00413872  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413875  750b                 jne 0x413882
// 00413877  894104               mov dword ptr [ecx + 4], eax
// 0041387a  8910                 mov dword ptr [eax], edx
// 0041387c  894204               mov dword ptr [edx + 4], eax
// 0041387f  c20400               ret 4
// 00413882  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413885  3b11                 cmp edx, dword ptr [ecx]
// 00413887  750a                 jne 0x413893
// 00413889  8901                 mov dword ptr [ecx], eax
// 0041388b  8910                 mov dword ptr [eax], edx
// 0041388d  894204               mov dword ptr [edx + 4], eax
// 00413890  c20400               ret 4
// 00413893  894108               mov dword ptr [ecx + 8], eax
// 00413896  8910                 mov dword ptr [eax], edx
// 00413898  894204               mov dword ptr [edx + 4], eax
// 0041389b  c20400               ret 4
// standard library map_str<string> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

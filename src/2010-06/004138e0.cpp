// from server: 100% by auto
// roc 2010-06 004138e0  unit: CutVerb  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004138e0
//
// 004138e0  8b542404             mov edx, dword ptr [esp + 4]
// 004138e4  8b02                 mov eax, dword ptr [edx]
// 004138e6  56                   push esi
// 004138e7  8b7008               mov esi, dword ptr [eax + 8]
// 004138ea  8932                 mov dword ptr [edx], esi
// 004138ec  8b7008               mov esi, dword ptr [eax + 8]
// 004138ef  807e4500             cmp byte ptr [esi + 0x45], 0
// 004138f3  7503                 jne 0x4138f8
// 004138f5  895604               mov dword ptr [esi + 4], edx
// 004138f8  8b7204               mov esi, dword ptr [edx + 4]
// 004138fb  897004               mov dword ptr [eax + 4], esi
// 004138fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413901  5e                   pop esi
// 00413902  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413905  750c                 jne 0x413913
// 00413907  894104               mov dword ptr [ecx + 4], eax
// 0041390a  895008               mov dword ptr [eax + 8], edx
// 0041390d  894204               mov dword ptr [edx + 4], eax
// 00413910  c20400               ret 4
// 00413913  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413916  3b5108               cmp edx, dword ptr [ecx + 8]
// 00413919  750c                 jne 0x413927
// 0041391b  894108               mov dword ptr [ecx + 8], eax
// 0041391e  895008               mov dword ptr [eax + 8], edx
// 00413921  894204               mov dword ptr [edx + 4], eax
// 00413924  c20400               ret 4
// 00413927  8901                 mov dword ptr [ecx], eax
// 00413929  895008               mov dword ptr [eax + 8], edx
// 0041392c  894204               mov dword ptr [edx + 4], eax
// 0041392f  c20400               ret 4
// standard library map_str<string> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

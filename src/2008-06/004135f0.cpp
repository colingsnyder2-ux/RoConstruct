// from server: 100% by auto
// roc 2008-06 004135f0  unit: CutVerb  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004135f0
//
// 004135f0  8b542404             mov edx, dword ptr [esp + 4]
// 004135f4  8b02                 mov eax, dword ptr [edx]
// 004135f6  56                   push esi
// 004135f7  8b7008               mov esi, dword ptr [eax + 8]
// 004135fa  8932                 mov dword ptr [edx], esi
// 004135fc  8b7008               mov esi, dword ptr [eax + 8]
// 004135ff  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413603  7503                 jne 0x413608
// 00413605  895604               mov dword ptr [esi + 4], edx
// 00413608  8b7204               mov esi, dword ptr [edx + 4]
// 0041360b  897004               mov dword ptr [eax + 4], esi
// 0041360e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413611  5e                   pop esi
// 00413612  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413615  750c                 jne 0x413623
// 00413617  894104               mov dword ptr [ecx + 4], eax
// 0041361a  895008               mov dword ptr [eax + 8], edx
// 0041361d  894204               mov dword ptr [edx + 4], eax
// 00413620  c20400               ret 4
// 00413623  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413626  3b5108               cmp edx, dword ptr [ecx + 8]
// 00413629  750c                 jne 0x413637
// 0041362b  894108               mov dword ptr [ecx + 8], eax
// 0041362e  895008               mov dword ptr [eax + 8], edx
// 00413631  894204               mov dword ptr [edx + 4], eax
// 00413634  c20400               ret 4
// 00413637  8901                 mov dword ptr [ecx], eax
// 00413639  895008               mov dword ptr [eax + 8], edx
// 0041363c  894204               mov dword ptr [edx + 4], eax
// 0041363f  c20400               ret 4
// standard library map_str<string> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

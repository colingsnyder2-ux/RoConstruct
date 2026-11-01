// from server: 100% by auto
// roc 2009-12 00413610  unit: CutVerb  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413610
//
// 00413610  8b542404             mov edx, dword ptr [esp + 4]
// 00413614  8b02                 mov eax, dword ptr [edx]
// 00413616  56                   push esi
// 00413617  8b7008               mov esi, dword ptr [eax + 8]
// 0041361a  8932                 mov dword ptr [edx], esi
// 0041361c  8b7008               mov esi, dword ptr [eax + 8]
// 0041361f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00413623  7503                 jne 0x413628
// 00413625  895604               mov dword ptr [esi + 4], edx
// 00413628  8b7204               mov esi, dword ptr [edx + 4]
// 0041362b  897004               mov dword ptr [eax + 4], esi
// 0041362e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00413631  5e                   pop esi
// 00413632  3b5104               cmp edx, dword ptr [ecx + 4]
// 00413635  750c                 jne 0x413643
// 00413637  894104               mov dword ptr [ecx + 4], eax
// 0041363a  895008               mov dword ptr [eax + 8], edx
// 0041363d  894204               mov dword ptr [edx + 4], eax
// 00413640  c20400               ret 4
// 00413643  8b4a04               mov ecx, dword ptr [edx + 4]
// 00413646  3b5108               cmp edx, dword ptr [ecx + 8]
// 00413649  750c                 jne 0x413657
// 0041364b  894108               mov dword ptr [ecx + 8], eax
// 0041364e  895008               mov dword ptr [eax + 8], edx
// 00413651  894204               mov dword ptr [edx + 4], eax
// 00413654  c20400               ret 4
// 00413657  8901                 mov dword ptr [ecx], eax
// 00413659  895008               mov dword ptr [eax + 8], edx
// 0041365c  894204               mov dword ptr [edx + 4], eax
// 0041365f  c20400               ret 4
// standard library map_str<string> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;

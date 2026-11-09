// from server: 100% by auto
// roc 2008-06 005870e0  unit: RBX::LocalScript  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005870e0
//
// 005870e0  8b542404             mov edx, dword ptr [esp + 4]
// 005870e4  8b02                 mov eax, dword ptr [edx]
// 005870e6  56                   push esi
// 005870e7  8b7008               mov esi, dword ptr [eax + 8]
// 005870ea  8932                 mov dword ptr [edx], esi
// 005870ec  8b7008               mov esi, dword ptr [eax + 8]
// 005870ef  807e4900             cmp byte ptr [esi + 0x49], 0
// 005870f3  7503                 jne 0x5870f8
// 005870f5  895604               mov dword ptr [esi + 4], edx
// 005870f8  8b7204               mov esi, dword ptr [edx + 4]
// 005870fb  897004               mov dword ptr [eax + 4], esi
// 005870fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00587101  5e                   pop esi
// 00587102  3b5104               cmp edx, dword ptr [ecx + 4]
// 00587105  750c                 jne 0x587113
// 00587107  894104               mov dword ptr [ecx + 4], eax
// 0058710a  895008               mov dword ptr [eax + 8], edx
// 0058710d  894204               mov dword ptr [edx + 4], eax
// 00587110  c20400               ret 4
// 00587113  8b4a04               mov ecx, dword ptr [edx + 4]
// 00587116  3b5108               cmp edx, dword ptr [ecx + 8]
// 00587119  750c                 jne 0x587127
// 0058711b  894108               mov dword ptr [ecx + 8], eax
// 0058711e  895008               mov dword ptr [eax + 8], edx
// 00587121  894204               mov dword ptr [edx + 4], eax
// 00587124  c20400               ret 4
// 00587127  8901                 mov dword ptr [ecx], eax
// 00587129  895008               mov dword ptr [eax + 8], edx
// 0058712c  894204               mov dword ptr [edx + 4], eax
// 0058712f  c20400               ret 4
// standard library map_str<pod32> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

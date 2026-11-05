// from server: 100% by auto
// roc 2009-12 005cd180  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd180
//
// 005cd180  8b542404             mov edx, dword ptr [esp + 4]
// 005cd184  8b4208               mov eax, dword ptr [edx + 8]
// 005cd187  56                   push esi
// 005cd188  8b30                 mov esi, dword ptr [eax]
// 005cd18a  897208               mov dword ptr [edx + 8], esi
// 005cd18d  8b30                 mov esi, dword ptr [eax]
// 005cd18f  807e2900             cmp byte ptr [esi + 0x29], 0
// 005cd193  7503                 jne 0x5cd198
// 005cd195  895604               mov dword ptr [esi + 4], edx
// 005cd198  8b7204               mov esi, dword ptr [edx + 4]
// 005cd19b  897004               mov dword ptr [eax + 4], esi
// 005cd19e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005cd1a1  5e                   pop esi
// 005cd1a2  3b5104               cmp edx, dword ptr [ecx + 4]
// 005cd1a5  750b                 jne 0x5cd1b2
// 005cd1a7  894104               mov dword ptr [ecx + 4], eax
// 005cd1aa  8910                 mov dword ptr [eax], edx
// 005cd1ac  894204               mov dword ptr [edx + 4], eax
// 005cd1af  c20400               ret 4
// 005cd1b2  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cd1b5  3b11                 cmp edx, dword ptr [ecx]
// 005cd1b7  750a                 jne 0x5cd1c3
// 005cd1b9  8901                 mov dword ptr [ecx], eax
// 005cd1bb  8910                 mov dword ptr [eax], edx
// 005cd1bd  894204               mov dword ptr [edx + 4], eax
// 005cd1c0  c20400               ret 4
// 005cd1c3  894108               mov dword ptr [ecx + 8], eax
// 005cd1c6  8910                 mov dword ptr [eax], edx
// 005cd1c8  894204               mov dword ptr [edx + 4], eax
// 005cd1cb  c20400               ret 4
// standard library set<string> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

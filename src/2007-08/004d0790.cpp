// from server: 100% by auto
// roc 2007-08 004d0790  unit: RBX::View::PartChunk  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0790
//
// 004d0790  8b542404             mov edx, dword ptr [esp + 4]
// 004d0794  8b4208               mov eax, dword ptr [edx + 8]
// 004d0797  56                   push esi
// 004d0798  8b30                 mov esi, dword ptr [eax]
// 004d079a  897208               mov dword ptr [edx + 8], esi
// 004d079d  8b30                 mov esi, dword ptr [eax]
// 004d079f  807e2900             cmp byte ptr [esi + 0x29], 0
// 004d07a3  7503                 jne 0x4d07a8
// 004d07a5  895604               mov dword ptr [esi + 4], edx
// 004d07a8  8b7204               mov esi, dword ptr [edx + 4]
// 004d07ab  897004               mov dword ptr [eax + 4], esi
// 004d07ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 004d07b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 004d07b4  5e                   pop esi
// 004d07b5  750b                 jne 0x4d07c2
// 004d07b7  894104               mov dword ptr [ecx + 4], eax
// 004d07ba  8910                 mov dword ptr [eax], edx
// 004d07bc  894204               mov dword ptr [edx + 4], eax
// 004d07bf  c20400               ret 4
// 004d07c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d07c5  3b11                 cmp edx, dword ptr [ecx]
// 004d07c7  750a                 jne 0x4d07d3
// 004d07c9  8901                 mov dword ptr [ecx], eax
// 004d07cb  8910                 mov dword ptr [eax], edx
// 004d07cd  894204               mov dword ptr [edx + 4], eax
// 004d07d0  c20400               ret 4
// 004d07d3  894108               mov dword ptr [ecx + 8], eax
// 004d07d6  8910                 mov dword ptr [eax], edx
// 004d07d8  894204               mov dword ptr [edx + 4], eax
// 004d07db  c20400               ret 4
// standard library set<string> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

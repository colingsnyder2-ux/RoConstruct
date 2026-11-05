// from server: 100% by auto
// roc 2007-08 004d0290  unit: RBX::TextureProxyBase  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0290
//
// 004d0290  8b542404             mov edx, dword ptr [esp + 4]
// 004d0294  8b02                 mov eax, dword ptr [edx]
// 004d0296  56                   push esi
// 004d0297  8b7008               mov esi, dword ptr [eax + 8]
// 004d029a  8932                 mov dword ptr [edx], esi
// 004d029c  8b7008               mov esi, dword ptr [eax + 8]
// 004d029f  807e2900             cmp byte ptr [esi + 0x29], 0
// 004d02a3  7503                 jne 0x4d02a8
// 004d02a5  895604               mov dword ptr [esi + 4], edx
// 004d02a8  8b7204               mov esi, dword ptr [edx + 4]
// 004d02ab  897004               mov dword ptr [eax + 4], esi
// 004d02ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 004d02b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 004d02b4  5e                   pop esi
// 004d02b5  750c                 jne 0x4d02c3
// 004d02b7  894104               mov dword ptr [ecx + 4], eax
// 004d02ba  895008               mov dword ptr [eax + 8], edx
// 004d02bd  894204               mov dword ptr [edx + 4], eax
// 004d02c0  c20400               ret 4
// 004d02c3  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d02c6  3b5108               cmp edx, dword ptr [ecx + 8]
// 004d02c9  750c                 jne 0x4d02d7
// 004d02cb  894108               mov dword ptr [ecx + 8], eax
// 004d02ce  895008               mov dword ptr [eax + 8], edx
// 004d02d1  894204               mov dword ptr [edx + 4], eax
// 004d02d4  c20400               ret 4
// 004d02d7  8901                 mov dword ptr [ecx], eax
// 004d02d9  895008               mov dword ptr [eax + 8], edx
// 004d02dc  894204               mov dword ptr [edx + 4], eax
// 004d02df  c20400               ret 4
// standard library set<string> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

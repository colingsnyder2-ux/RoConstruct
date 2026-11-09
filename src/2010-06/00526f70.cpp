// from server: 100% by auto
// roc 2010-06 00526f70  unit: RBX::ViewG3D  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526f70
//
// 00526f70  8b542404             mov edx, dword ptr [esp + 4]
// 00526f74  8b02                 mov eax, dword ptr [edx]
// 00526f76  56                   push esi
// 00526f77  8b7008               mov esi, dword ptr [eax + 8]
// 00526f7a  8932                 mov dword ptr [edx], esi
// 00526f7c  8b7008               mov esi, dword ptr [eax + 8]
// 00526f7f  807e2900             cmp byte ptr [esi + 0x29], 0
// 00526f83  7503                 jne 0x526f88
// 00526f85  895604               mov dword ptr [esi + 4], edx
// 00526f88  8b7204               mov esi, dword ptr [edx + 4]
// 00526f8b  897004               mov dword ptr [eax + 4], esi
// 00526f8e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00526f91  5e                   pop esi
// 00526f92  3b5104               cmp edx, dword ptr [ecx + 4]
// 00526f95  750c                 jne 0x526fa3
// 00526f97  894104               mov dword ptr [ecx + 4], eax
// 00526f9a  895008               mov dword ptr [eax + 8], edx
// 00526f9d  894204               mov dword ptr [edx + 4], eax
// 00526fa0  c20400               ret 4
// 00526fa3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00526fa6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00526fa9  750c                 jne 0x526fb7
// 00526fab  894108               mov dword ptr [ecx + 8], eax
// 00526fae  895008               mov dword ptr [eax + 8], edx
// 00526fb1  894204               mov dword ptr [edx + 4], eax
// 00526fb4  c20400               ret 4
// 00526fb7  8901                 mov dword ptr [ecx], eax
// 00526fb9  895008               mov dword ptr [eax + 8], edx
// 00526fbc  894204               mov dword ptr [edx + 4], eax
// 00526fbf  c20400               ret 4
// standard library set<string> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

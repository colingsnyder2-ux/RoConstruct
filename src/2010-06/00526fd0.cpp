// from server: 100% by auto
// roc 2010-06 00526fd0  unit: RBX::ViewG3D  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526fd0
//
// 00526fd0  8b542404             mov edx, dword ptr [esp + 4]
// 00526fd4  8b4208               mov eax, dword ptr [edx + 8]
// 00526fd7  56                   push esi
// 00526fd8  8b30                 mov esi, dword ptr [eax]
// 00526fda  897208               mov dword ptr [edx + 8], esi
// 00526fdd  8b30                 mov esi, dword ptr [eax]
// 00526fdf  807e2900             cmp byte ptr [esi + 0x29], 0
// 00526fe3  7503                 jne 0x526fe8
// 00526fe5  895604               mov dword ptr [esi + 4], edx
// 00526fe8  8b7204               mov esi, dword ptr [edx + 4]
// 00526feb  897004               mov dword ptr [eax + 4], esi
// 00526fee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00526ff1  5e                   pop esi
// 00526ff2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00526ff5  750b                 jne 0x527002
// 00526ff7  894104               mov dword ptr [ecx + 4], eax
// 00526ffa  8910                 mov dword ptr [eax], edx
// 00526ffc  894204               mov dword ptr [edx + 4], eax
// 00526fff  c20400               ret 4
// 00527002  8b4a04               mov ecx, dword ptr [edx + 4]
// 00527005  3b11                 cmp edx, dword ptr [ecx]
// 00527007  750a                 jne 0x527013
// 00527009  8901                 mov dword ptr [ecx], eax
// 0052700b  8910                 mov dword ptr [eax], edx
// 0052700d  894204               mov dword ptr [edx + 4], eax
// 00527010  c20400               ret 4
// 00527013  894108               mov dword ptr [ecx + 8], eax
// 00527016  8910                 mov dword ptr [eax], edx
// 00527018  894204               mov dword ptr [edx + 4], eax
// 0052701b  c20400               ret 4
// standard library set<string> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

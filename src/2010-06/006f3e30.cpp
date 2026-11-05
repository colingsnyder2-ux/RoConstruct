// from server: 100% by auto
// roc 2010-06 006f3e30  unit: RBX::VStudioTool::?$EventDesc  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3e30
//
// 006f3e30  8b542404             mov edx, dword ptr [esp + 4]
// 006f3e34  8b4208               mov eax, dword ptr [edx + 8]
// 006f3e37  56                   push esi
// 006f3e38  8b30                 mov esi, dword ptr [eax]
// 006f3e3a  897208               mov dword ptr [edx + 8], esi
// 006f3e3d  8b30                 mov esi, dword ptr [eax]
// 006f3e3f  807e0e00             cmp byte ptr [esi + 0xe], 0
// 006f3e43  7503                 jne 0x6f3e48
// 006f3e45  895604               mov dword ptr [esi + 4], edx
// 006f3e48  8b7204               mov esi, dword ptr [edx + 4]
// 006f3e4b  897004               mov dword ptr [eax + 4], esi
// 006f3e4e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006f3e51  5e                   pop esi
// 006f3e52  3b5104               cmp edx, dword ptr [ecx + 4]
// 006f3e55  750b                 jne 0x6f3e62
// 006f3e57  894104               mov dword ptr [ecx + 4], eax
// 006f3e5a  8910                 mov dword ptr [eax], edx
// 006f3e5c  894204               mov dword ptr [edx + 4], eax
// 006f3e5f  c20400               ret 4
// 006f3e62  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f3e65  3b11                 cmp edx, dword ptr [ecx]
// 006f3e67  750a                 jne 0x6f3e73
// 006f3e69  8901                 mov dword ptr [ecx], eax
// 006f3e6b  8910                 mov dword ptr [eax], edx
// 006f3e6d  894204               mov dword ptr [edx + 4], eax
// 006f3e70  c20400               ret 4
// 006f3e73  894108               mov dword ptr [ecx + 8], eax
// 006f3e76  8910                 mov dword ptr [eax], edx
// 006f3e78  894204               mov dword ptr [edx + 4], eax
// 006f3e7b  c20400               ret 4
// standard library set<char> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;

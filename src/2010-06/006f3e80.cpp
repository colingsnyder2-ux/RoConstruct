// from server: 100% by auto
// roc 2010-06 006f3e80  unit: RBX::VStudioTool::?$EventDesc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3e80
//
// 006f3e80  8b542404             mov edx, dword ptr [esp + 4]
// 006f3e84  8b02                 mov eax, dword ptr [edx]
// 006f3e86  56                   push esi
// 006f3e87  8b7008               mov esi, dword ptr [eax + 8]
// 006f3e8a  8932                 mov dword ptr [edx], esi
// 006f3e8c  8b7008               mov esi, dword ptr [eax + 8]
// 006f3e8f  807e0e00             cmp byte ptr [esi + 0xe], 0
// 006f3e93  7503                 jne 0x6f3e98
// 006f3e95  895604               mov dword ptr [esi + 4], edx
// 006f3e98  8b7204               mov esi, dword ptr [edx + 4]
// 006f3e9b  897004               mov dword ptr [eax + 4], esi
// 006f3e9e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006f3ea1  5e                   pop esi
// 006f3ea2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006f3ea5  750c                 jne 0x6f3eb3
// 006f3ea7  894104               mov dword ptr [ecx + 4], eax
// 006f3eaa  895008               mov dword ptr [eax + 8], edx
// 006f3ead  894204               mov dword ptr [edx + 4], eax
// 006f3eb0  c20400               ret 4
// 006f3eb3  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f3eb6  3b5108               cmp edx, dword ptr [ecx + 8]
// 006f3eb9  750c                 jne 0x6f3ec7
// 006f3ebb  894108               mov dword ptr [ecx + 8], eax
// 006f3ebe  895008               mov dword ptr [eax + 8], edx
// 006f3ec1  894204               mov dword ptr [edx + 4], eax
// 006f3ec4  c20400               ret 4
// 006f3ec7  8901                 mov dword ptr [ecx], eax
// 006f3ec9  895008               mov dword ptr [eax + 8], edx
// 006f3ecc  894204               mov dword ptr [edx + 4], eax
// 006f3ecf  c20400               ret 4
// standard library set<char> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;

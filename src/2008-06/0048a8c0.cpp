// from server: 100% by auto
// roc 2008-06 0048a8c0  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048a8c0
//
// 0048a8c0  8b542404             mov edx, dword ptr [esp + 4]
// 0048a8c4  8b4208               mov eax, dword ptr [edx + 8]
// 0048a8c7  56                   push esi
// 0048a8c8  8b30                 mov esi, dword ptr [eax]
// 0048a8ca  897208               mov dword ptr [edx + 8], esi
// 0048a8cd  8b30                 mov esi, dword ptr [eax]
// 0048a8cf  807e0e00             cmp byte ptr [esi + 0xe], 0
// 0048a8d3  7503                 jne 0x48a8d8
// 0048a8d5  895604               mov dword ptr [esi + 4], edx
// 0048a8d8  8b7204               mov esi, dword ptr [edx + 4]
// 0048a8db  897004               mov dword ptr [eax + 4], esi
// 0048a8de  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0048a8e1  5e                   pop esi
// 0048a8e2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0048a8e5  750b                 jne 0x48a8f2
// 0048a8e7  894104               mov dword ptr [ecx + 4], eax
// 0048a8ea  8910                 mov dword ptr [eax], edx
// 0048a8ec  894204               mov dword ptr [edx + 4], eax
// 0048a8ef  c20400               ret 4
// 0048a8f2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048a8f5  3b11                 cmp edx, dword ptr [ecx]
// 0048a8f7  750a                 jne 0x48a903
// 0048a8f9  8901                 mov dword ptr [ecx], eax
// 0048a8fb  8910                 mov dword ptr [eax], edx
// 0048a8fd  894204               mov dword ptr [edx + 4], eax
// 0048a900  c20400               ret 4
// 0048a903  894108               mov dword ptr [ecx + 8], eax
// 0048a906  8910                 mov dword ptr [eax], edx
// 0048a908  894204               mov dword ptr [edx + 4], eax
// 0048a90b  c20400               ret 4
// standard library set<char> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;

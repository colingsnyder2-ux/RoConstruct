// from server: 100% by auto
// roc 2009-12 0071a380  unit: RBX::VPhysicsService::?$EventDesc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0071a380
//
// 0071a380  8b542404             mov edx, dword ptr [esp + 4]
// 0071a384  8b02                 mov eax, dword ptr [edx]
// 0071a386  56                   push esi
// 0071a387  8b7008               mov esi, dword ptr [eax + 8]
// 0071a38a  8932                 mov dword ptr [edx], esi
// 0071a38c  8b7008               mov esi, dword ptr [eax + 8]
// 0071a38f  807e1100             cmp byte ptr [esi + 0x11], 0
// 0071a393  7503                 jne 0x71a398
// 0071a395  895604               mov dword ptr [esi + 4], edx
// 0071a398  8b7204               mov esi, dword ptr [edx + 4]
// 0071a39b  897004               mov dword ptr [eax + 4], esi
// 0071a39e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0071a3a1  5e                   pop esi
// 0071a3a2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0071a3a5  750c                 jne 0x71a3b3
// 0071a3a7  894104               mov dword ptr [ecx + 4], eax
// 0071a3aa  895008               mov dword ptr [eax + 8], edx
// 0071a3ad  894204               mov dword ptr [edx + 4], eax
// 0071a3b0  c20400               ret 4
// 0071a3b3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0071a3b6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0071a3b9  750c                 jne 0x71a3c7
// 0071a3bb  894108               mov dword ptr [ecx + 8], eax
// 0071a3be  895008               mov dword ptr [eax + 8], edx
// 0071a3c1  894204               mov dword ptr [edx + 4], eax
// 0071a3c4  c20400               ret 4
// 0071a3c7  8901                 mov dword ptr [ecx], eax
// 0071a3c9  895008               mov dword ptr [eax + 8], edx
// 0071a3cc  894204               mov dword ptr [edx + 4], eax
// 0071a3cf  c20400               ret 4
// standard library set<ptr> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

// from server: 100% by auto
// roc 2009-06 00432120  unit: RBX::Soundscape::VSoundId::?$XItem  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432120
//
// 00432120  8b542404             mov edx, dword ptr [esp + 4]
// 00432124  8b02                 mov eax, dword ptr [edx]
// 00432126  56                   push esi
// 00432127  8b7008               mov esi, dword ptr [eax + 8]
// 0043212a  8932                 mov dword ptr [edx], esi
// 0043212c  8b7008               mov esi, dword ptr [eax + 8]
// 0043212f  807e1100             cmp byte ptr [esi + 0x11], 0
// 00432133  7503                 jne 0x432138
// 00432135  895604               mov dword ptr [esi + 4], edx
// 00432138  8b7204               mov esi, dword ptr [edx + 4]
// 0043213b  897004               mov dword ptr [eax + 4], esi
// 0043213e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00432141  5e                   pop esi
// 00432142  3b5104               cmp edx, dword ptr [ecx + 4]
// 00432145  750c                 jne 0x432153
// 00432147  894104               mov dword ptr [ecx + 4], eax
// 0043214a  895008               mov dword ptr [eax + 8], edx
// 0043214d  894204               mov dword ptr [edx + 4], eax
// 00432150  c20400               ret 4
// 00432153  8b4a04               mov ecx, dword ptr [edx + 4]
// 00432156  3b5108               cmp edx, dword ptr [ecx + 8]
// 00432159  750c                 jne 0x432167
// 0043215b  894108               mov dword ptr [ecx + 8], eax
// 0043215e  895008               mov dword ptr [eax + 8], edx
// 00432161  894204               mov dword ptr [edx + 4], eax
// 00432164  c20400               ret 4
// 00432167  8901                 mov dword ptr [ecx], eax
// 00432169  895008               mov dword ptr [eax + 8], edx
// 0043216c  894204               mov dword ptr [edx + 4], eax
// 0043216f  c20400               ret 4
// standard library set<ptr> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

// from server: 100% by auto
// roc 2008-06 004dc620  unit: RBX::ViewNew::ViewG3D  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc620
//
// 004dc620  8b542404             mov edx, dword ptr [esp + 4]
// 004dc624  8b4208               mov eax, dword ptr [edx + 8]
// 004dc627  56                   push esi
// 004dc628  8b30                 mov esi, dword ptr [eax]
// 004dc62a  897208               mov dword ptr [edx + 8], esi
// 004dc62d  8b30                 mov esi, dword ptr [eax]
// 004dc62f  807e3500             cmp byte ptr [esi + 0x35], 0
// 004dc633  7503                 jne 0x4dc638
// 004dc635  895604               mov dword ptr [esi + 4], edx
// 004dc638  8b7204               mov esi, dword ptr [edx + 4]
// 004dc63b  897004               mov dword ptr [eax + 4], esi
// 004dc63e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004dc641  5e                   pop esi
// 004dc642  3b5104               cmp edx, dword ptr [ecx + 4]
// 004dc645  750b                 jne 0x4dc652
// 004dc647  894104               mov dword ptr [ecx + 4], eax
// 004dc64a  8910                 mov dword ptr [eax], edx
// 004dc64c  894204               mov dword ptr [edx + 4], eax
// 004dc64f  c20400               ret 4
// 004dc652  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dc655  3b11                 cmp edx, dword ptr [ecx]
// 004dc657  750a                 jne 0x4dc663
// 004dc659  8901                 mov dword ptr [ecx], eax
// 004dc65b  8910                 mov dword ptr [eax], edx
// 004dc65d  894204               mov dword ptr [edx + 4], eax
// 004dc660  c20400               ret 4
// 004dc663  894108               mov dword ptr [ecx + 8], eax
// 004dc666  8910                 mov dword ptr [eax], edx
// 004dc668  894204               mov dword ptr [edx + 4], eax
// 004dc66b  c20400               ret 4
// standard library set<pod40> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

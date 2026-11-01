// from server: 100% by auto
// roc 2009-12 007e61d0  unit: RBX::ExclusiveArbiter  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e61d0
//
// 007e61d0  8b542404             mov edx, dword ptr [esp + 4]
// 007e61d4  8b4208               mov eax, dword ptr [edx + 8]
// 007e61d7  56                   push esi
// 007e61d8  8b30                 mov esi, dword ptr [eax]
// 007e61da  897208               mov dword ptr [edx + 8], esi
// 007e61dd  8b30                 mov esi, dword ptr [eax]
// 007e61df  807e1500             cmp byte ptr [esi + 0x15], 0
// 007e61e3  7503                 jne 0x7e61e8
// 007e61e5  895604               mov dword ptr [esi + 4], edx
// 007e61e8  8b7204               mov esi, dword ptr [edx + 4]
// 007e61eb  897004               mov dword ptr [eax + 4], esi
// 007e61ee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007e61f1  5e                   pop esi
// 007e61f2  3b5104               cmp edx, dword ptr [ecx + 4]
// 007e61f5  750b                 jne 0x7e6202
// 007e61f7  894104               mov dword ptr [ecx + 4], eax
// 007e61fa  8910                 mov dword ptr [eax], edx
// 007e61fc  894204               mov dword ptr [edx + 4], eax
// 007e61ff  c20400               ret 4
// 007e6202  8b4a04               mov ecx, dword ptr [edx + 4]
// 007e6205  3b11                 cmp edx, dword ptr [ecx]
// 007e6207  750a                 jne 0x7e6213
// 007e6209  8901                 mov dword ptr [ecx], eax
// 007e620b  8910                 mov dword ptr [eax], edx
// 007e620d  894204               mov dword ptr [edx + 4], eax
// 007e6210  c20400               ret 4
// 007e6213  894108               mov dword ptr [ecx + 8], eax
// 007e6216  8910                 mov dword ptr [eax], edx
// 007e6218  894204               mov dword ptr [edx + 4], eax
// 007e621b  c20400               ret 4
// standard library set<pod8> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

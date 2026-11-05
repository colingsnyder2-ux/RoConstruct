// from server: 100% by auto
// roc 2008-06 005b6c40  unit: RBX::DropperTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6c40
//
// 005b6c40  8b542404             mov edx, dword ptr [esp + 4]
// 005b6c44  8b02                 mov eax, dword ptr [edx]
// 005b6c46  56                   push esi
// 005b6c47  8b7008               mov esi, dword ptr [eax + 8]
// 005b6c4a  8932                 mov dword ptr [edx], esi
// 005b6c4c  8b7008               mov esi, dword ptr [eax + 8]
// 005b6c4f  807e1500             cmp byte ptr [esi + 0x15], 0
// 005b6c53  7503                 jne 0x5b6c58
// 005b6c55  895604               mov dword ptr [esi + 4], edx
// 005b6c58  8b7204               mov esi, dword ptr [edx + 4]
// 005b6c5b  897004               mov dword ptr [eax + 4], esi
// 005b6c5e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005b6c61  5e                   pop esi
// 005b6c62  3b5104               cmp edx, dword ptr [ecx + 4]
// 005b6c65  750c                 jne 0x5b6c73
// 005b6c67  894104               mov dword ptr [ecx + 4], eax
// 005b6c6a  895008               mov dword ptr [eax + 8], edx
// 005b6c6d  894204               mov dword ptr [edx + 4], eax
// 005b6c70  c20400               ret 4
// 005b6c73  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b6c76  3b5108               cmp edx, dword ptr [ecx + 8]
// 005b6c79  750c                 jne 0x5b6c87
// 005b6c7b  894108               mov dword ptr [ecx + 8], eax
// 005b6c7e  895008               mov dword ptr [eax + 8], edx
// 005b6c81  894204               mov dword ptr [edx + 4], eax
// 005b6c84  c20400               ret 4
// 005b6c87  8901                 mov dword ptr [ecx], eax
// 005b6c89  895008               mov dword ptr [eax + 8], edx
// 005b6c8c  894204               mov dword ptr [edx + 4], eax
// 005b6c8f  c20400               ret 4
// standard library set<pod8> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2009-12 006b3a20  unit: RBX::DropperTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b3a20
//
// 006b3a20  8b542404             mov edx, dword ptr [esp + 4]
// 006b3a24  8b02                 mov eax, dword ptr [edx]
// 006b3a26  56                   push esi
// 006b3a27  8b7008               mov esi, dword ptr [eax + 8]
// 006b3a2a  8932                 mov dword ptr [edx], esi
// 006b3a2c  8b7008               mov esi, dword ptr [eax + 8]
// 006b3a2f  807e3500             cmp byte ptr [esi + 0x35], 0
// 006b3a33  7503                 jne 0x6b3a38
// 006b3a35  895604               mov dword ptr [esi + 4], edx
// 006b3a38  8b7204               mov esi, dword ptr [edx + 4]
// 006b3a3b  897004               mov dword ptr [eax + 4], esi
// 006b3a3e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006b3a41  5e                   pop esi
// 006b3a42  3b5104               cmp edx, dword ptr [ecx + 4]
// 006b3a45  750c                 jne 0x6b3a53
// 006b3a47  894104               mov dword ptr [ecx + 4], eax
// 006b3a4a  895008               mov dword ptr [eax + 8], edx
// 006b3a4d  894204               mov dword ptr [edx + 4], eax
// 006b3a50  c20400               ret 4
// 006b3a53  8b4a04               mov ecx, dword ptr [edx + 4]
// 006b3a56  3b5108               cmp edx, dword ptr [ecx + 8]
// 006b3a59  750c                 jne 0x6b3a67
// 006b3a5b  894108               mov dword ptr [ecx + 8], eax
// 006b3a5e  895008               mov dword ptr [eax + 8], edx
// 006b3a61  894204               mov dword ptr [edx + 4], eax
// 006b3a64  c20400               ret 4
// 006b3a67  8901                 mov dword ptr [ecx], eax
// 006b3a69  895008               mov dword ptr [eax + 8], edx
// 006b3a6c  894204               mov dword ptr [edx + 4], eax
// 006b3a6f  c20400               ret 4
// standard library set<pod40> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2008-06 00647df0  unit: RBX::Block  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00647df0
//
// 00647df0  8b542404             mov edx, dword ptr [esp + 4]
// 00647df4  8b02                 mov eax, dword ptr [edx]
// 00647df6  56                   push esi
// 00647df7  8b7008               mov esi, dword ptr [eax + 8]
// 00647dfa  8932                 mov dword ptr [edx], esi
// 00647dfc  8b7008               mov esi, dword ptr [eax + 8]
// 00647dff  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 00647e03  7503                 jne 0x647e08
// 00647e05  895604               mov dword ptr [esi + 4], edx
// 00647e08  8b7204               mov esi, dword ptr [edx + 4]
// 00647e0b  897004               mov dword ptr [eax + 4], esi
// 00647e0e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00647e11  5e                   pop esi
// 00647e12  3b5104               cmp edx, dword ptr [ecx + 4]
// 00647e15  750c                 jne 0x647e23
// 00647e17  894104               mov dword ptr [ecx + 4], eax
// 00647e1a  895008               mov dword ptr [eax + 8], edx
// 00647e1d  894204               mov dword ptr [edx + 4], eax
// 00647e20  c20400               ret 4
// 00647e23  8b4a04               mov ecx, dword ptr [edx + 4]
// 00647e26  3b5108               cmp edx, dword ptr [ecx + 8]
// 00647e29  750c                 jne 0x647e37
// 00647e2b  894108               mov dword ptr [ecx + 8], eax
// 00647e2e  895008               mov dword ptr [eax + 8], edx
// 00647e31  894204               mov dword ptr [edx + 4], eax
// 00647e34  c20400               ret 4
// 00647e37  8901                 mov dword ptr [ecx], eax
// 00647e39  895008               mov dword ptr [eax + 8], edx
// 00647e3c  894204               mov dword ptr [edx + 4], eax
// 00647e3f  c20400               ret 4
// standard library set<pod16> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

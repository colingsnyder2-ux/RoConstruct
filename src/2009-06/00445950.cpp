// from server: 100% by auto
// roc 2009-06 00445950  unit: CRobloxApp  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445950
//
// 00445950  8b542404             mov edx, dword ptr [esp + 4]
// 00445954  8b02                 mov eax, dword ptr [edx]
// 00445956  56                   push esi
// 00445957  8b7008               mov esi, dword ptr [eax + 8]
// 0044595a  8932                 mov dword ptr [edx], esi
// 0044595c  8b7008               mov esi, dword ptr [eax + 8]
// 0044595f  807e2500             cmp byte ptr [esi + 0x25], 0
// 00445963  7503                 jne 0x445968
// 00445965  895604               mov dword ptr [esi + 4], edx
// 00445968  8b7204               mov esi, dword ptr [edx + 4]
// 0044596b  897004               mov dword ptr [eax + 4], esi
// 0044596e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00445971  5e                   pop esi
// 00445972  3b5104               cmp edx, dword ptr [ecx + 4]
// 00445975  750c                 jne 0x445983
// 00445977  894104               mov dword ptr [ecx + 4], eax
// 0044597a  895008               mov dword ptr [eax + 8], edx
// 0044597d  894204               mov dword ptr [edx + 4], eax
// 00445980  c20400               ret 4
// 00445983  8b4a04               mov ecx, dword ptr [edx + 4]
// 00445986  3b5108               cmp edx, dword ptr [ecx + 8]
// 00445989  750c                 jne 0x445997
// 0044598b  894108               mov dword ptr [ecx + 8], eax
// 0044598e  895008               mov dword ptr [eax + 8], edx
// 00445991  894204               mov dword ptr [edx + 4], eax
// 00445994  c20400               ret 4
// 00445997  8901                 mov dword ptr [ecx], eax
// 00445999  895008               mov dword ptr [eax + 8], edx
// 0044599c  894204               mov dword ptr [edx + 4], eax
// 0044599f  c20400               ret 4
// standard library set<pod24> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

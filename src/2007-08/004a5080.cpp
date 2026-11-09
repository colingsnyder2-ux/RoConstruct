// from server: 100% by auto
// roc 2007-08 004a5080  unit: RBX::Network::Server::ClientProxy  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a5080
//
// 004a5080  8b542404             mov edx, dword ptr [esp + 4]
// 004a5084  8b02                 mov eax, dword ptr [edx]
// 004a5086  56                   push esi
// 004a5087  8b7008               mov esi, dword ptr [eax + 8]
// 004a508a  8932                 mov dword ptr [edx], esi
// 004a508c  8b7008               mov esi, dword ptr [eax + 8]
// 004a508f  807e2500             cmp byte ptr [esi + 0x25], 0
// 004a5093  7503                 jne 0x4a5098
// 004a5095  895604               mov dword ptr [esi + 4], edx
// 004a5098  8b7204               mov esi, dword ptr [edx + 4]
// 004a509b  897004               mov dword ptr [eax + 4], esi
// 004a509e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a50a1  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a50a4  5e                   pop esi
// 004a50a5  750c                 jne 0x4a50b3
// 004a50a7  894104               mov dword ptr [ecx + 4], eax
// 004a50aa  895008               mov dword ptr [eax + 8], edx
// 004a50ad  894204               mov dword ptr [edx + 4], eax
// 004a50b0  c20400               ret 4
// 004a50b3  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a50b6  3b5108               cmp edx, dword ptr [ecx + 8]
// 004a50b9  750c                 jne 0x4a50c7
// 004a50bb  894108               mov dword ptr [ecx + 8], eax
// 004a50be  895008               mov dword ptr [eax + 8], edx
// 004a50c1  894204               mov dword ptr [edx + 4], eax
// 004a50c4  c20400               ret 4
// 004a50c7  8901                 mov dword ptr [ecx], eax
// 004a50c9  895008               mov dword ptr [eax + 8], edx
// 004a50cc  894204               mov dword ptr [edx + 4], eax
// 004a50cf  c20400               ret 4
// standard library set<pod24> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

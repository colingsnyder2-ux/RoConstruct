// from server: 100% by auto
// roc 2009-06 004dca00  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dca00
//
// 004dca00  8b542404             mov edx, dword ptr [esp + 4]
// 004dca04  8b02                 mov eax, dword ptr [edx]
// 004dca06  56                   push esi
// 004dca07  8b7008               mov esi, dword ptr [eax + 8]
// 004dca0a  8932                 mov dword ptr [edx], esi
// 004dca0c  8b7008               mov esi, dword ptr [eax + 8]
// 004dca0f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004dca13  7503                 jne 0x4dca18
// 004dca15  895604               mov dword ptr [esi + 4], edx
// 004dca18  8b7204               mov esi, dword ptr [edx + 4]
// 004dca1b  897004               mov dword ptr [eax + 4], esi
// 004dca1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004dca21  5e                   pop esi
// 004dca22  3b5104               cmp edx, dword ptr [ecx + 4]
// 004dca25  750c                 jne 0x4dca33
// 004dca27  894104               mov dword ptr [ecx + 4], eax
// 004dca2a  895008               mov dword ptr [eax + 8], edx
// 004dca2d  894204               mov dword ptr [edx + 4], eax
// 004dca30  c20400               ret 4
// 004dca33  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dca36  3b5108               cmp edx, dword ptr [ecx + 8]
// 004dca39  750c                 jne 0x4dca47
// 004dca3b  894108               mov dword ptr [ecx + 8], eax
// 004dca3e  895008               mov dword ptr [eax + 8], edx
// 004dca41  894204               mov dword ptr [edx + 4], eax
// 004dca44  c20400               ret 4
// 004dca47  8901                 mov dword ptr [ecx], eax
// 004dca49  895008               mov dword ptr [eax + 8], edx
// 004dca4c  894204               mov dword ptr [edx + 4], eax
// 004dca4f  c20400               ret 4
// standard library set<pod32> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

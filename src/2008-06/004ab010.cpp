// from server: 100% by auto
// roc 2008-06 004ab010  unit: RBX::Network::Replicator  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab010
//
// 004ab010  8b542404             mov edx, dword ptr [esp + 4]
// 004ab014  8b02                 mov eax, dword ptr [edx]
// 004ab016  56                   push esi
// 004ab017  8b7008               mov esi, dword ptr [eax + 8]
// 004ab01a  8932                 mov dword ptr [edx], esi
// 004ab01c  8b7008               mov esi, dword ptr [eax + 8]
// 004ab01f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 004ab023  7503                 jne 0x4ab028
// 004ab025  895604               mov dword ptr [esi + 4], edx
// 004ab028  8b7204               mov esi, dword ptr [edx + 4]
// 004ab02b  897004               mov dword ptr [eax + 4], esi
// 004ab02e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004ab031  5e                   pop esi
// 004ab032  3b5104               cmp edx, dword ptr [ecx + 4]
// 004ab035  750c                 jne 0x4ab043
// 004ab037  894104               mov dword ptr [ecx + 4], eax
// 004ab03a  895008               mov dword ptr [eax + 8], edx
// 004ab03d  894204               mov dword ptr [edx + 4], eax
// 004ab040  c20400               ret 4
// 004ab043  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ab046  3b5108               cmp edx, dword ptr [ecx + 8]
// 004ab049  750c                 jne 0x4ab057
// 004ab04b  894108               mov dword ptr [ecx + 8], eax
// 004ab04e  895008               mov dword ptr [eax + 8], edx
// 004ab051  894204               mov dword ptr [edx + 4], eax
// 004ab054  c20400               ret 4
// 004ab057  8901                 mov dword ptr [ecx], eax
// 004ab059  895008               mov dword ptr [eax + 8], edx
// 004ab05c  894204               mov dword ptr [edx + 4], eax
// 004ab05f  c20400               ret 4
// standard library set<pod48> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

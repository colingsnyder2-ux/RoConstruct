// from server: 100% by auto
// roc 2010-06 004bfe50  unit: RBX::Network::VPlayer::?$EventDesc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004bfe50
//
// 004bfe50  8b542404             mov edx, dword ptr [esp + 4]
// 004bfe54  8b02                 mov eax, dword ptr [edx]
// 004bfe56  56                   push esi
// 004bfe57  8b7008               mov esi, dword ptr [eax + 8]
// 004bfe5a  8932                 mov dword ptr [edx], esi
// 004bfe5c  8b7008               mov esi, dword ptr [eax + 8]
// 004bfe5f  807e3100             cmp byte ptr [esi + 0x31], 0
// 004bfe63  7503                 jne 0x4bfe68
// 004bfe65  895604               mov dword ptr [esi + 4], edx
// 004bfe68  8b7204               mov esi, dword ptr [edx + 4]
// 004bfe6b  897004               mov dword ptr [eax + 4], esi
// 004bfe6e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004bfe71  5e                   pop esi
// 004bfe72  3b5104               cmp edx, dword ptr [ecx + 4]
// 004bfe75  750c                 jne 0x4bfe83
// 004bfe77  894104               mov dword ptr [ecx + 4], eax
// 004bfe7a  895008               mov dword ptr [eax + 8], edx
// 004bfe7d  894204               mov dword ptr [edx + 4], eax
// 004bfe80  c20400               ret 4
// 004bfe83  8b4a04               mov ecx, dword ptr [edx + 4]
// 004bfe86  3b5108               cmp edx, dword ptr [ecx + 8]
// 004bfe89  750c                 jne 0x4bfe97
// 004bfe8b  894108               mov dword ptr [ecx + 8], eax
// 004bfe8e  895008               mov dword ptr [eax + 8], edx
// 004bfe91  894204               mov dword ptr [edx + 4], eax
// 004bfe94  c20400               ret 4
// 004bfe97  8901                 mov dword ptr [ecx], eax
// 004bfe99  895008               mov dword ptr [eax + 8], edx
// 004bfe9c  894204               mov dword ptr [edx + 4], eax
// 004bfe9f  c20400               ret 4
// standard library set<pod36> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

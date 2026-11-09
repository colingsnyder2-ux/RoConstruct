// from server: 100% by auto
// roc 2009-06 00516a50  unit: RBX::MeshRefPartAdapter  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516a50
//
// 00516a50  8b542404             mov edx, dword ptr [esp + 4]
// 00516a54  8b02                 mov eax, dword ptr [edx]
// 00516a56  56                   push esi
// 00516a57  8b7008               mov esi, dword ptr [eax + 8]
// 00516a5a  8932                 mov dword ptr [edx], esi
// 00516a5c  8b7008               mov esi, dword ptr [eax + 8]
// 00516a5f  807e2100             cmp byte ptr [esi + 0x21], 0
// 00516a63  7503                 jne 0x516a68
// 00516a65  895604               mov dword ptr [esi + 4], edx
// 00516a68  8b7204               mov esi, dword ptr [edx + 4]
// 00516a6b  897004               mov dword ptr [eax + 4], esi
// 00516a6e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00516a71  5e                   pop esi
// 00516a72  3b5104               cmp edx, dword ptr [ecx + 4]
// 00516a75  750c                 jne 0x516a83
// 00516a77  894104               mov dword ptr [ecx + 4], eax
// 00516a7a  895008               mov dword ptr [eax + 8], edx
// 00516a7d  894204               mov dword ptr [edx + 4], eax
// 00516a80  c20400               ret 4
// 00516a83  8b4a04               mov ecx, dword ptr [edx + 4]
// 00516a86  3b5108               cmp edx, dword ptr [ecx + 8]
// 00516a89  750c                 jne 0x516a97
// 00516a8b  894108               mov dword ptr [ecx + 8], eax
// 00516a8e  895008               mov dword ptr [eax + 8], edx
// 00516a91  894204               mov dword ptr [edx + 4], eax
// 00516a94  c20400               ret 4
// 00516a97  8901                 mov dword ptr [ecx], eax
// 00516a99  895008               mov dword ptr [eax + 8], edx
// 00516a9c  894204               mov dword ptr [edx + 4], eax
// 00516a9f  c20400               ret 4
// standard library set<pod20> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

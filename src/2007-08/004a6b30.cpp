// from server: 100% by auto
// roc 2007-08 004a6b30  unit: RBX::Network::Replicator  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a6b30
//
// 004a6b30  8b542404             mov edx, dword ptr [esp + 4]
// 004a6b34  8b4208               mov eax, dword ptr [edx + 8]
// 004a6b37  56                   push esi
// 004a6b38  8b30                 mov esi, dword ptr [eax]
// 004a6b3a  897208               mov dword ptr [edx + 8], esi
// 004a6b3d  8b30                 mov esi, dword ptr [eax]
// 004a6b3f  807e2500             cmp byte ptr [esi + 0x25], 0
// 004a6b43  7503                 jne 0x4a6b48
// 004a6b45  895604               mov dword ptr [esi + 4], edx
// 004a6b48  8b7204               mov esi, dword ptr [edx + 4]
// 004a6b4b  897004               mov dword ptr [eax + 4], esi
// 004a6b4e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a6b51  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a6b54  5e                   pop esi
// 004a6b55  750b                 jne 0x4a6b62
// 004a6b57  894104               mov dword ptr [ecx + 4], eax
// 004a6b5a  8910                 mov dword ptr [eax], edx
// 004a6b5c  894204               mov dword ptr [edx + 4], eax
// 004a6b5f  c20400               ret 4
// 004a6b62  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a6b65  3b11                 cmp edx, dword ptr [ecx]
// 004a6b67  750a                 jne 0x4a6b73
// 004a6b69  8901                 mov dword ptr [ecx], eax
// 004a6b6b  8910                 mov dword ptr [eax], edx
// 004a6b6d  894204               mov dword ptr [edx + 4], eax
// 004a6b70  c20400               ret 4
// 004a6b73  894108               mov dword ptr [ecx + 8], eax
// 004a6b76  8910                 mov dword ptr [eax], edx
// 004a6b78  894204               mov dword ptr [edx + 4], eax
// 004a6b7b  c20400               ret 4
// standard library set<pod24> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

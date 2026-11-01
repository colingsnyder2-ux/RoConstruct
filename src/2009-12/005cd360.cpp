// from server: 100% by auto
// roc 2009-12 005cd360  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd360
//
// 005cd360  8b542404             mov edx, dword ptr [esp + 4]
// 005cd364  8b4208               mov eax, dword ptr [edx + 8]
// 005cd367  56                   push esi
// 005cd368  8b30                 mov esi, dword ptr [eax]
// 005cd36a  897208               mov dword ptr [edx + 8], esi
// 005cd36d  8b30                 mov esi, dword ptr [eax]
// 005cd36f  807e2100             cmp byte ptr [esi + 0x21], 0
// 005cd373  7503                 jne 0x5cd378
// 005cd375  895604               mov dword ptr [esi + 4], edx
// 005cd378  8b7204               mov esi, dword ptr [edx + 4]
// 005cd37b  897004               mov dword ptr [eax + 4], esi
// 005cd37e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005cd381  5e                   pop esi
// 005cd382  3b5104               cmp edx, dword ptr [ecx + 4]
// 005cd385  750b                 jne 0x5cd392
// 005cd387  894104               mov dword ptr [ecx + 4], eax
// 005cd38a  8910                 mov dword ptr [eax], edx
// 005cd38c  894204               mov dword ptr [edx + 4], eax
// 005cd38f  c20400               ret 4
// 005cd392  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cd395  3b11                 cmp edx, dword ptr [ecx]
// 005cd397  750a                 jne 0x5cd3a3
// 005cd399  8901                 mov dword ptr [ecx], eax
// 005cd39b  8910                 mov dword ptr [eax], edx
// 005cd39d  894204               mov dword ptr [edx + 4], eax
// 005cd3a0  c20400               ret 4
// 005cd3a3  894108               mov dword ptr [ecx + 8], eax
// 005cd3a6  8910                 mov dword ptr [eax], edx
// 005cd3a8  894204               mov dword ptr [edx + 4], eax
// 005cd3ab  c20400               ret 4
// standard library set<pod20> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

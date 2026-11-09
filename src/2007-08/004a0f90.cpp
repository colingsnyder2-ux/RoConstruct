// from server: 100% by auto
// roc 2007-08 004a0f90  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a0f90
//
// 004a0f90  8b542404             mov edx, dword ptr [esp + 4]
// 004a0f94  8b4208               mov eax, dword ptr [edx + 8]
// 004a0f97  56                   push esi
// 004a0f98  8b30                 mov esi, dword ptr [eax]
// 004a0f9a  897208               mov dword ptr [edx + 8], esi
// 004a0f9d  8b30                 mov esi, dword ptr [eax]
// 004a0f9f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a0fa3  7503                 jne 0x4a0fa8
// 004a0fa5  895604               mov dword ptr [esi + 4], edx
// 004a0fa8  8b7204               mov esi, dword ptr [edx + 4]
// 004a0fab  897004               mov dword ptr [eax + 4], esi
// 004a0fae  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a0fb1  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a0fb4  5e                   pop esi
// 004a0fb5  750b                 jne 0x4a0fc2
// 004a0fb7  894104               mov dword ptr [ecx + 4], eax
// 004a0fba  8910                 mov dword ptr [eax], edx
// 004a0fbc  894204               mov dword ptr [edx + 4], eax
// 004a0fbf  c20400               ret 4
// 004a0fc2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a0fc5  3b11                 cmp edx, dword ptr [ecx]
// 004a0fc7  750a                 jne 0x4a0fd3
// 004a0fc9  8901                 mov dword ptr [ecx], eax
// 004a0fcb  8910                 mov dword ptr [eax], edx
// 004a0fcd  894204               mov dword ptr [edx + 4], eax
// 004a0fd0  c20400               ret 4
// 004a0fd3  894108               mov dword ptr [ecx + 8], eax
// 004a0fd6  8910                 mov dword ptr [eax], edx
// 004a0fd8  894204               mov dword ptr [edx + 4], eax
// 004a0fdb  c20400               ret 4
// standard library set<pod32> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

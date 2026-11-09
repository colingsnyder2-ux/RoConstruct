// from server: 100% by auto
// roc 2007-08 004a0ee0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a0ee0
//
// 004a0ee0  8b542404             mov edx, dword ptr [esp + 4]
// 004a0ee4  8b02                 mov eax, dword ptr [edx]
// 004a0ee6  56                   push esi
// 004a0ee7  8b7008               mov esi, dword ptr [eax + 8]
// 004a0eea  8932                 mov dword ptr [edx], esi
// 004a0eec  8b7008               mov esi, dword ptr [eax + 8]
// 004a0eef  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a0ef3  7503                 jne 0x4a0ef8
// 004a0ef5  895604               mov dword ptr [esi + 4], edx
// 004a0ef8  8b7204               mov esi, dword ptr [edx + 4]
// 004a0efb  897004               mov dword ptr [eax + 4], esi
// 004a0efe  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a0f01  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a0f04  5e                   pop esi
// 004a0f05  750c                 jne 0x4a0f13
// 004a0f07  894104               mov dword ptr [ecx + 4], eax
// 004a0f0a  895008               mov dword ptr [eax + 8], edx
// 004a0f0d  894204               mov dword ptr [edx + 4], eax
// 004a0f10  c20400               ret 4
// 004a0f13  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a0f16  3b5108               cmp edx, dword ptr [ecx + 8]
// 004a0f19  750c                 jne 0x4a0f27
// 004a0f1b  894108               mov dword ptr [ecx + 8], eax
// 004a0f1e  895008               mov dword ptr [eax + 8], edx
// 004a0f21  894204               mov dword ptr [edx + 4], eax
// 004a0f24  c20400               ret 4
// 004a0f27  8901                 mov dword ptr [ecx], eax
// 004a0f29  895008               mov dword ptr [eax + 8], edx
// 004a0f2c  894204               mov dword ptr [edx + 4], eax
// 004a0f2f  c20400               ret 4
// standard library set<pod32> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

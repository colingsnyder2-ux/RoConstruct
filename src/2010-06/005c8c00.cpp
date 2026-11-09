// from server: 100% by auto
// roc 2010-06 005c8c00  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005c8c00
//
// 005c8c00  8b542404             mov edx, dword ptr [esp + 4]
// 005c8c04  8b02                 mov eax, dword ptr [edx]
// 005c8c06  56                   push esi
// 005c8c07  8b7008               mov esi, dword ptr [eax + 8]
// 005c8c0a  8932                 mov dword ptr [edx], esi
// 005c8c0c  8b7008               mov esi, dword ptr [eax + 8]
// 005c8c0f  807e1500             cmp byte ptr [esi + 0x15], 0
// 005c8c13  7503                 jne 0x5c8c18
// 005c8c15  895604               mov dword ptr [esi + 4], edx
// 005c8c18  8b7204               mov esi, dword ptr [edx + 4]
// 005c8c1b  897004               mov dword ptr [eax + 4], esi
// 005c8c1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005c8c21  5e                   pop esi
// 005c8c22  3b5104               cmp edx, dword ptr [ecx + 4]
// 005c8c25  750c                 jne 0x5c8c33
// 005c8c27  894104               mov dword ptr [ecx + 4], eax
// 005c8c2a  895008               mov dword ptr [eax + 8], edx
// 005c8c2d  894204               mov dword ptr [edx + 4], eax
// 005c8c30  c20400               ret 4
// 005c8c33  8b4a04               mov ecx, dword ptr [edx + 4]
// 005c8c36  3b5108               cmp edx, dword ptr [ecx + 8]
// 005c8c39  750c                 jne 0x5c8c47
// 005c8c3b  894108               mov dword ptr [ecx + 8], eax
// 005c8c3e  895008               mov dword ptr [eax + 8], edx
// 005c8c41  894204               mov dword ptr [edx + 4], eax
// 005c8c44  c20400               ret 4
// 005c8c47  8901                 mov dword ptr [ecx], eax
// 005c8c49  895008               mov dword ptr [eax + 8], edx
// 005c8c4c  894204               mov dword ptr [edx + 4], eax
// 005c8c4f  c20400               ret 4
// standard library set<pod8> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

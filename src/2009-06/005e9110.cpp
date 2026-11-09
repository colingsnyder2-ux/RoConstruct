// from server: 100% by auto
// roc 2009-06 005e9110  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e9110
//
// 005e9110  8b542404             mov edx, dword ptr [esp + 4]
// 005e9114  8b02                 mov eax, dword ptr [edx]
// 005e9116  56                   push esi
// 005e9117  8b7008               mov esi, dword ptr [eax + 8]
// 005e911a  8932                 mov dword ptr [edx], esi
// 005e911c  8b7008               mov esi, dword ptr [eax + 8]
// 005e911f  807e1500             cmp byte ptr [esi + 0x15], 0
// 005e9123  7503                 jne 0x5e9128
// 005e9125  895604               mov dword ptr [esi + 4], edx
// 005e9128  8b7204               mov esi, dword ptr [edx + 4]
// 005e912b  897004               mov dword ptr [eax + 4], esi
// 005e912e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e9131  5e                   pop esi
// 005e9132  3b5104               cmp edx, dword ptr [ecx + 4]
// 005e9135  750c                 jne 0x5e9143
// 005e9137  894104               mov dword ptr [ecx + 4], eax
// 005e913a  895008               mov dword ptr [eax + 8], edx
// 005e913d  894204               mov dword ptr [edx + 4], eax
// 005e9140  c20400               ret 4
// 005e9143  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e9146  3b5108               cmp edx, dword ptr [ecx + 8]
// 005e9149  750c                 jne 0x5e9157
// 005e914b  894108               mov dword ptr [ecx + 8], eax
// 005e914e  895008               mov dword ptr [eax + 8], edx
// 005e9151  894204               mov dword ptr [edx + 4], eax
// 005e9154  c20400               ret 4
// 005e9157  8901                 mov dword ptr [ecx], eax
// 005e9159  895008               mov dword ptr [eax + 8], edx
// 005e915c  894204               mov dword ptr [edx + 4], eax
// 005e915f  c20400               ret 4
// standard library set<pod8> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2009-06 006d2c10  unit: RBX::Block  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d2c10
//
// 006d2c10  8b542404             mov edx, dword ptr [esp + 4]
// 006d2c14  8b02                 mov eax, dword ptr [edx]
// 006d2c16  56                   push esi
// 006d2c17  8b7008               mov esi, dword ptr [eax + 8]
// 006d2c1a  8932                 mov dword ptr [edx], esi
// 006d2c1c  8b7008               mov esi, dword ptr [eax + 8]
// 006d2c1f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 006d2c23  7503                 jne 0x6d2c28
// 006d2c25  895604               mov dword ptr [esi + 4], edx
// 006d2c28  8b7204               mov esi, dword ptr [edx + 4]
// 006d2c2b  897004               mov dword ptr [eax + 4], esi
// 006d2c2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006d2c31  5e                   pop esi
// 006d2c32  3b5104               cmp edx, dword ptr [ecx + 4]
// 006d2c35  750c                 jne 0x6d2c43
// 006d2c37  894104               mov dword ptr [ecx + 4], eax
// 006d2c3a  895008               mov dword ptr [eax + 8], edx
// 006d2c3d  894204               mov dword ptr [edx + 4], eax
// 006d2c40  c20400               ret 4
// 006d2c43  8b4a04               mov ecx, dword ptr [edx + 4]
// 006d2c46  3b5108               cmp edx, dword ptr [ecx + 8]
// 006d2c49  750c                 jne 0x6d2c57
// 006d2c4b  894108               mov dword ptr [ecx + 8], eax
// 006d2c4e  895008               mov dword ptr [eax + 8], edx
// 006d2c51  894204               mov dword ptr [edx + 4], eax
// 006d2c54  c20400               ret 4
// 006d2c57  8901                 mov dword ptr [ecx], eax
// 006d2c59  895008               mov dword ptr [eax + 8], edx
// 006d2c5c  894204               mov dword ptr [edx + 4], eax
// 006d2c5f  c20400               ret 4
// standard library set<pod16> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

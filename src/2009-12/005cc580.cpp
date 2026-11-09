// from server: 100% by auto
// roc 2009-12 005cc580  unit: RBX::MeshRefPartAdapter  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc580
//
// 005cc580  8b542404             mov edx, dword ptr [esp + 4]
// 005cc584  8b02                 mov eax, dword ptr [edx]
// 005cc586  56                   push esi
// 005cc587  8b7008               mov esi, dword ptr [eax + 8]
// 005cc58a  8932                 mov dword ptr [edx], esi
// 005cc58c  8b7008               mov esi, dword ptr [eax + 8]
// 005cc58f  807e2100             cmp byte ptr [esi + 0x21], 0
// 005cc593  7503                 jne 0x5cc598
// 005cc595  895604               mov dword ptr [esi + 4], edx
// 005cc598  8b7204               mov esi, dword ptr [edx + 4]
// 005cc59b  897004               mov dword ptr [eax + 4], esi
// 005cc59e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005cc5a1  5e                   pop esi
// 005cc5a2  3b5104               cmp edx, dword ptr [ecx + 4]
// 005cc5a5  750c                 jne 0x5cc5b3
// 005cc5a7  894104               mov dword ptr [ecx + 4], eax
// 005cc5aa  895008               mov dword ptr [eax + 8], edx
// 005cc5ad  894204               mov dword ptr [edx + 4], eax
// 005cc5b0  c20400               ret 4
// 005cc5b3  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cc5b6  3b5108               cmp edx, dword ptr [ecx + 8]
// 005cc5b9  750c                 jne 0x5cc5c7
// 005cc5bb  894108               mov dword ptr [ecx + 8], eax
// 005cc5be  895008               mov dword ptr [eax + 8], edx
// 005cc5c1  894204               mov dword ptr [edx + 4], eax
// 005cc5c4  c20400               ret 4
// 005cc5c7  8901                 mov dword ptr [ecx], eax
// 005cc5c9  895008               mov dword ptr [eax + 8], edx
// 005cc5cc  894204               mov dword ptr [edx + 4], eax
// 005cc5cf  c20400               ret 4
// standard library set<pod20> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2010-06 0052d0b0  unit: RBX::VTextureProxyBase::?$sp_counted_impl_p  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052d0b0
//
// 0052d0b0  8b542404             mov edx, dword ptr [esp + 4]
// 0052d0b4  8b4208               mov eax, dword ptr [edx + 8]
// 0052d0b7  56                   push esi
// 0052d0b8  8b30                 mov esi, dword ptr [eax]
// 0052d0ba  897208               mov dword ptr [edx + 8], esi
// 0052d0bd  8b30                 mov esi, dword ptr [eax]
// 0052d0bf  807e2100             cmp byte ptr [esi + 0x21], 0
// 0052d0c3  7503                 jne 0x52d0c8
// 0052d0c5  895604               mov dword ptr [esi + 4], edx
// 0052d0c8  8b7204               mov esi, dword ptr [edx + 4]
// 0052d0cb  897004               mov dword ptr [eax + 4], esi
// 0052d0ce  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0052d0d1  5e                   pop esi
// 0052d0d2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0052d0d5  750b                 jne 0x52d0e2
// 0052d0d7  894104               mov dword ptr [ecx + 4], eax
// 0052d0da  8910                 mov dword ptr [eax], edx
// 0052d0dc  894204               mov dword ptr [edx + 4], eax
// 0052d0df  c20400               ret 4
// 0052d0e2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0052d0e5  3b11                 cmp edx, dword ptr [ecx]
// 0052d0e7  750a                 jne 0x52d0f3
// 0052d0e9  8901                 mov dword ptr [ecx], eax
// 0052d0eb  8910                 mov dword ptr [eax], edx
// 0052d0ed  894204               mov dword ptr [edx + 4], eax
// 0052d0f0  c20400               ret 4
// 0052d0f3  894108               mov dword ptr [ecx + 8], eax
// 0052d0f6  8910                 mov dword ptr [eax], edx
// 0052d0f8  894204               mov dword ptr [edx + 4], eax
// 0052d0fb  c20400               ret 4
// standard library set<pod20> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

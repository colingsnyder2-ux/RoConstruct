// from server: 100% by auto
// roc 2008-06 004452a0  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004452a0
//
// 004452a0  8b542404             mov edx, dword ptr [esp + 4]
// 004452a4  8b4208               mov eax, dword ptr [edx + 8]
// 004452a7  56                   push esi
// 004452a8  8b30                 mov esi, dword ptr [eax]
// 004452aa  897208               mov dword ptr [edx + 8], esi
// 004452ad  8b30                 mov esi, dword ptr [eax]
// 004452af  807e1500             cmp byte ptr [esi + 0x15], 0
// 004452b3  7503                 jne 0x4452b8
// 004452b5  895604               mov dword ptr [esi + 4], edx
// 004452b8  8b7204               mov esi, dword ptr [edx + 4]
// 004452bb  897004               mov dword ptr [eax + 4], esi
// 004452be  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004452c1  5e                   pop esi
// 004452c2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004452c5  750b                 jne 0x4452d2
// 004452c7  894104               mov dword ptr [ecx + 4], eax
// 004452ca  8910                 mov dword ptr [eax], edx
// 004452cc  894204               mov dword ptr [edx + 4], eax
// 004452cf  c20400               ret 4
// 004452d2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004452d5  3b11                 cmp edx, dword ptr [ecx]
// 004452d7  750a                 jne 0x4452e3
// 004452d9  8901                 mov dword ptr [ecx], eax
// 004452db  8910                 mov dword ptr [eax], edx
// 004452dd  894204               mov dword ptr [edx + 4], eax
// 004452e0  c20400               ret 4
// 004452e3  894108               mov dword ptr [ecx + 8], eax
// 004452e6  8910                 mov dword ptr [eax], edx
// 004452e8  894204               mov dword ptr [edx + 4], eax
// 004452eb  c20400               ret 4
// standard library set<pod8> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

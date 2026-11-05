// from server: 100% by auto
// roc 2009-06 0063ea80  unit: RBX::Accoutrement  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ea80
//
// 0063ea80  8b542404             mov edx, dword ptr [esp + 4]
// 0063ea84  8b4208               mov eax, dword ptr [edx + 8]
// 0063ea87  56                   push esi
// 0063ea88  8b30                 mov esi, dword ptr [eax]
// 0063ea8a  897208               mov dword ptr [edx + 8], esi
// 0063ea8d  8b30                 mov esi, dword ptr [eax]
// 0063ea8f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0063ea93  7503                 jne 0x63ea98
// 0063ea95  895604               mov dword ptr [esi + 4], edx
// 0063ea98  8b7204               mov esi, dword ptr [edx + 4]
// 0063ea9b  897004               mov dword ptr [eax + 4], esi
// 0063ea9e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0063eaa1  5e                   pop esi
// 0063eaa2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0063eaa5  750b                 jne 0x63eab2
// 0063eaa7  894104               mov dword ptr [ecx + 4], eax
// 0063eaaa  8910                 mov dword ptr [eax], edx
// 0063eaac  894204               mov dword ptr [edx + 4], eax
// 0063eaaf  c20400               ret 4
// 0063eab2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063eab5  3b11                 cmp edx, dword ptr [ecx]
// 0063eab7  750a                 jne 0x63eac3
// 0063eab9  8901                 mov dword ptr [ecx], eax
// 0063eabb  8910                 mov dword ptr [eax], edx
// 0063eabd  894204               mov dword ptr [edx + 4], eax
// 0063eac0  c20400               ret 4
// 0063eac3  894108               mov dword ptr [ecx + 8], eax
// 0063eac6  8910                 mov dword ptr [eax], edx
// 0063eac8  894204               mov dword ptr [edx + 4], eax
// 0063eacb  c20400               ret 4
// standard library set<pod32> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

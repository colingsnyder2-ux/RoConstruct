// from server: 100% by auto
// roc 2009-06 006fc890  unit: RBX::BrickBuilder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc890
//
// 006fc890  8b542404             mov edx, dword ptr [esp + 4]
// 006fc894  8b4208               mov eax, dword ptr [edx + 8]
// 006fc897  56                   push esi
// 006fc898  8b30                 mov esi, dword ptr [eax]
// 006fc89a  897208               mov dword ptr [edx + 8], esi
// 006fc89d  8b30                 mov esi, dword ptr [eax]
// 006fc89f  807e1500             cmp byte ptr [esi + 0x15], 0
// 006fc8a3  7503                 jne 0x6fc8a8
// 006fc8a5  895604               mov dword ptr [esi + 4], edx
// 006fc8a8  8b7204               mov esi, dword ptr [edx + 4]
// 006fc8ab  897004               mov dword ptr [eax + 4], esi
// 006fc8ae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006fc8b1  5e                   pop esi
// 006fc8b2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006fc8b5  750b                 jne 0x6fc8c2
// 006fc8b7  894104               mov dword ptr [ecx + 4], eax
// 006fc8ba  8910                 mov dword ptr [eax], edx
// 006fc8bc  894204               mov dword ptr [edx + 4], eax
// 006fc8bf  c20400               ret 4
// 006fc8c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 006fc8c5  3b11                 cmp edx, dword ptr [ecx]
// 006fc8c7  750a                 jne 0x6fc8d3
// 006fc8c9  8901                 mov dword ptr [ecx], eax
// 006fc8cb  8910                 mov dword ptr [eax], edx
// 006fc8cd  894204               mov dword ptr [edx + 4], eax
// 006fc8d0  c20400               ret 4
// 006fc8d3  894108               mov dword ptr [ecx + 8], eax
// 006fc8d6  8910                 mov dword ptr [eax], edx
// 006fc8d8  894204               mov dword ptr [edx + 4], eax
// 006fc8db  c20400               ret 4
// standard library set<pod8> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

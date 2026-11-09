// from server: 100% by auto
// roc 2007-08 00545990  unit: RBX::MD5HasherImpl  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545990
//
// 00545990  8b542404             mov edx, dword ptr [esp + 4]
// 00545994  8b4208               mov eax, dword ptr [edx + 8]
// 00545997  56                   push esi
// 00545998  8b30                 mov esi, dword ptr [eax]
// 0054599a  897208               mov dword ptr [edx + 8], esi
// 0054599d  8b30                 mov esi, dword ptr [eax]
// 0054599f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005459a3  7503                 jne 0x5459a8
// 005459a5  895604               mov dword ptr [esi + 4], edx
// 005459a8  8b7204               mov esi, dword ptr [edx + 4]
// 005459ab  897004               mov dword ptr [eax + 4], esi
// 005459ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 005459b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 005459b4  5e                   pop esi
// 005459b5  750b                 jne 0x5459c2
// 005459b7  894104               mov dword ptr [ecx + 4], eax
// 005459ba  8910                 mov dword ptr [eax], edx
// 005459bc  894204               mov dword ptr [edx + 4], eax
// 005459bf  c20400               ret 4
// 005459c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 005459c5  3b11                 cmp edx, dword ptr [ecx]
// 005459c7  750a                 jne 0x5459d3
// 005459c9  8901                 mov dword ptr [ecx], eax
// 005459cb  8910                 mov dword ptr [eax], edx
// 005459cd  894204               mov dword ptr [edx + 4], eax
// 005459d0  c20400               ret 4
// 005459d3  894108               mov dword ptr [ecx + 8], eax
// 005459d6  8910                 mov dword ptr [eax], edx
// 005459d8  894204               mov dword ptr [edx + 4], eax
// 005459db  c20400               ret 4
// standard library set<pod48> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

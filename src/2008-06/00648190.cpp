// from server: 100% by auto
// roc 2008-06 00648190  unit: RBX::Block  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648190
//
// 00648190  8b542404             mov edx, dword ptr [esp + 4]
// 00648194  8b4208               mov eax, dword ptr [edx + 8]
// 00648197  56                   push esi
// 00648198  8b30                 mov esi, dword ptr [eax]
// 0064819a  897208               mov dword ptr [edx + 8], esi
// 0064819d  8b30                 mov esi, dword ptr [eax]
// 0064819f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 006481a3  7503                 jne 0x6481a8
// 006481a5  895604               mov dword ptr [esi + 4], edx
// 006481a8  8b7204               mov esi, dword ptr [edx + 4]
// 006481ab  897004               mov dword ptr [eax + 4], esi
// 006481ae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006481b1  5e                   pop esi
// 006481b2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006481b5  750b                 jne 0x6481c2
// 006481b7  894104               mov dword ptr [ecx + 4], eax
// 006481ba  8910                 mov dword ptr [eax], edx
// 006481bc  894204               mov dword ptr [edx + 4], eax
// 006481bf  c20400               ret 4
// 006481c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 006481c5  3b11                 cmp edx, dword ptr [ecx]
// 006481c7  750a                 jne 0x6481d3
// 006481c9  8901                 mov dword ptr [ecx], eax
// 006481cb  8910                 mov dword ptr [eax], edx
// 006481cd  894204               mov dword ptr [edx + 4], eax
// 006481d0  c20400               ret 4
// 006481d3  894108               mov dword ptr [ecx + 8], eax
// 006481d6  8910                 mov dword ptr [eax], edx
// 006481d8  894204               mov dword ptr [edx + 4], eax
// 006481db  c20400               ret 4
// standard library set<pod16> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

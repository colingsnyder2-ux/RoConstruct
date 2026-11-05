// from server: 100% by auto
// roc 2009-06 00622270  unit: RBX::RootInstance  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622270
//
// 00622270  8b542404             mov edx, dword ptr [esp + 4]
// 00622274  8b4208               mov eax, dword ptr [edx + 8]
// 00622277  56                   push esi
// 00622278  8b30                 mov esi, dword ptr [eax]
// 0062227a  897208               mov dword ptr [edx + 8], esi
// 0062227d  8b30                 mov esi, dword ptr [eax]
// 0062227f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00622283  7503                 jne 0x622288
// 00622285  895604               mov dword ptr [esi + 4], edx
// 00622288  8b7204               mov esi, dword ptr [edx + 4]
// 0062228b  897004               mov dword ptr [eax + 4], esi
// 0062228e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00622291  5e                   pop esi
// 00622292  3b5104               cmp edx, dword ptr [ecx + 4]
// 00622295  750b                 jne 0x6222a2
// 00622297  894104               mov dword ptr [ecx + 4], eax
// 0062229a  8910                 mov dword ptr [eax], edx
// 0062229c  894204               mov dword ptr [edx + 4], eax
// 0062229f  c20400               ret 4
// 006222a2  8b4a04               mov ecx, dword ptr [edx + 4]
// 006222a5  3b11                 cmp edx, dword ptr [ecx]
// 006222a7  750a                 jne 0x6222b3
// 006222a9  8901                 mov dword ptr [ecx], eax
// 006222ab  8910                 mov dword ptr [eax], edx
// 006222ad  894204               mov dword ptr [edx + 4], eax
// 006222b0  c20400               ret 4
// 006222b3  894108               mov dword ptr [ecx + 8], eax
// 006222b6  8910                 mov dword ptr [eax], edx
// 006222b8  894204               mov dword ptr [edx + 4], eax
// 006222bb  c20400               ret 4
// standard library set<pod36> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

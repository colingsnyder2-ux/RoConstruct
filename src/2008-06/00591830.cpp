// from server: 100% by auto
// roc 2008-06 00591830  unit: RBX::RootInstance  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00591830
//
// 00591830  8b542404             mov edx, dword ptr [esp + 4]
// 00591834  8b4208               mov eax, dword ptr [edx + 8]
// 00591837  56                   push esi
// 00591838  8b30                 mov esi, dword ptr [eax]
// 0059183a  897208               mov dword ptr [edx + 8], esi
// 0059183d  8b30                 mov esi, dword ptr [eax]
// 0059183f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00591843  7503                 jne 0x591848
// 00591845  895604               mov dword ptr [esi + 4], edx
// 00591848  8b7204               mov esi, dword ptr [edx + 4]
// 0059184b  897004               mov dword ptr [eax + 4], esi
// 0059184e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00591851  5e                   pop esi
// 00591852  3b5104               cmp edx, dword ptr [ecx + 4]
// 00591855  750b                 jne 0x591862
// 00591857  894104               mov dword ptr [ecx + 4], eax
// 0059185a  8910                 mov dword ptr [eax], edx
// 0059185c  894204               mov dword ptr [edx + 4], eax
// 0059185f  c20400               ret 4
// 00591862  8b4a04               mov ecx, dword ptr [edx + 4]
// 00591865  3b11                 cmp edx, dword ptr [ecx]
// 00591867  750a                 jne 0x591873
// 00591869  8901                 mov dword ptr [ecx], eax
// 0059186b  8910                 mov dword ptr [eax], edx
// 0059186d  894204               mov dword ptr [edx + 4], eax
// 00591870  c20400               ret 4
// 00591873  894108               mov dword ptr [ecx + 8], eax
// 00591876  8910                 mov dword ptr [eax], edx
// 00591878  894204               mov dword ptr [edx + 4], eax
// 0059187b  c20400               ret 4
// standard library set<pod36> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

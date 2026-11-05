// from server: 100% by auto
// roc 2007-08 004cd710  unit: 0RBX::View  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cd710
//
// 004cd710  8b542404             mov edx, dword ptr [esp + 4]
// 004cd714  8b4208               mov eax, dword ptr [edx + 8]
// 004cd717  56                   push esi
// 004cd718  8b30                 mov esi, dword ptr [eax]
// 004cd71a  897208               mov dword ptr [edx + 8], esi
// 004cd71d  8b30                 mov esi, dword ptr [eax]
// 004cd71f  807e2100             cmp byte ptr [esi + 0x21], 0
// 004cd723  7503                 jne 0x4cd728
// 004cd725  895604               mov dword ptr [esi + 4], edx
// 004cd728  8b7204               mov esi, dword ptr [edx + 4]
// 004cd72b  897004               mov dword ptr [eax + 4], esi
// 004cd72e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004cd731  3b5104               cmp edx, dword ptr [ecx + 4]
// 004cd734  5e                   pop esi
// 004cd735  750b                 jne 0x4cd742
// 004cd737  894104               mov dword ptr [ecx + 4], eax
// 004cd73a  8910                 mov dword ptr [eax], edx
// 004cd73c  894204               mov dword ptr [edx + 4], eax
// 004cd73f  c20400               ret 4
// 004cd742  8b4a04               mov ecx, dword ptr [edx + 4]
// 004cd745  3b11                 cmp edx, dword ptr [ecx]
// 004cd747  750a                 jne 0x4cd753
// 004cd749  8901                 mov dword ptr [ecx], eax
// 004cd74b  8910                 mov dword ptr [eax], edx
// 004cd74d  894204               mov dword ptr [edx + 4], eax
// 004cd750  c20400               ret 4
// 004cd753  894108               mov dword ptr [ecx + 8], eax
// 004cd756  8910                 mov dword ptr [eax], edx
// 004cd758  894204               mov dword ptr [edx + 4], eax
// 004cd75b  c20400               ret 4
// standard library set<pod20> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

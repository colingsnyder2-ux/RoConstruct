// from server: 100% by auto
// roc 2010-06 0063fcb0  unit: RBX::VVisit::?$BoundFuncDesc  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063fcb0
//
// 0063fcb0  8b542404             mov edx, dword ptr [esp + 4]
// 0063fcb4  8b4208               mov eax, dword ptr [edx + 8]
// 0063fcb7  56                   push esi
// 0063fcb8  8b30                 mov esi, dword ptr [eax]
// 0063fcba  897208               mov dword ptr [edx + 8], esi
// 0063fcbd  8b30                 mov esi, dword ptr [eax]
// 0063fcbf  807e3500             cmp byte ptr [esi + 0x35], 0
// 0063fcc3  7503                 jne 0x63fcc8
// 0063fcc5  895604               mov dword ptr [esi + 4], edx
// 0063fcc8  8b7204               mov esi, dword ptr [edx + 4]
// 0063fccb  897004               mov dword ptr [eax + 4], esi
// 0063fcce  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0063fcd1  5e                   pop esi
// 0063fcd2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0063fcd5  750b                 jne 0x63fce2
// 0063fcd7  894104               mov dword ptr [ecx + 4], eax
// 0063fcda  8910                 mov dword ptr [eax], edx
// 0063fcdc  894204               mov dword ptr [edx + 4], eax
// 0063fcdf  c20400               ret 4
// 0063fce2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063fce5  3b11                 cmp edx, dword ptr [ecx]
// 0063fce7  750a                 jne 0x63fcf3
// 0063fce9  8901                 mov dword ptr [ecx], eax
// 0063fceb  8910                 mov dword ptr [eax], edx
// 0063fced  894204               mov dword ptr [edx + 4], eax
// 0063fcf0  c20400               ret 4
// 0063fcf3  894108               mov dword ptr [ecx + 8], eax
// 0063fcf6  8910                 mov dword ptr [eax], edx
// 0063fcf8  894204               mov dword ptr [edx + 4], eax
// 0063fcfb  c20400               ret 4
// standard library set<pod40> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

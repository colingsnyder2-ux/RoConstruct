// from server: 100% by auto
// roc 2010-06 00757600  unit: RBX::PrismPoly  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00757600
//
// 00757600  8b542404             mov edx, dword ptr [esp + 4]
// 00757604  8b4208               mov eax, dword ptr [edx + 8]
// 00757607  56                   push esi
// 00757608  8b30                 mov esi, dword ptr [eax]
// 0075760a  897208               mov dword ptr [edx + 8], esi
// 0075760d  8b30                 mov esi, dword ptr [eax]
// 0075760f  807e2500             cmp byte ptr [esi + 0x25], 0
// 00757613  7503                 jne 0x757618
// 00757615  895604               mov dword ptr [esi + 4], edx
// 00757618  8b7204               mov esi, dword ptr [edx + 4]
// 0075761b  897004               mov dword ptr [eax + 4], esi
// 0075761e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00757621  5e                   pop esi
// 00757622  3b5104               cmp edx, dword ptr [ecx + 4]
// 00757625  750b                 jne 0x757632
// 00757627  894104               mov dword ptr [ecx + 4], eax
// 0075762a  8910                 mov dword ptr [eax], edx
// 0075762c  894204               mov dword ptr [edx + 4], eax
// 0075762f  c20400               ret 4
// 00757632  8b4a04               mov ecx, dword ptr [edx + 4]
// 00757635  3b11                 cmp edx, dword ptr [ecx]
// 00757637  750a                 jne 0x757643
// 00757639  8901                 mov dword ptr [ecx], eax
// 0075763b  8910                 mov dword ptr [eax], edx
// 0075763d  894204               mov dword ptr [edx + 4], eax
// 00757640  c20400               ret 4
// 00757643  894108               mov dword ptr [ecx + 8], eax
// 00757646  8910                 mov dword ptr [eax], edx
// 00757648  894204               mov dword ptr [edx + 4], eax
// 0075764b  c20400               ret 4
// standard library set<pod24> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2009-12 006bd420  unit: CPropGrid::UpdateItemsJob  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bd420
//
// 006bd420  8b542404             mov edx, dword ptr [esp + 4]
// 006bd424  8b4208               mov eax, dword ptr [edx + 8]
// 006bd427  56                   push esi
// 006bd428  8b30                 mov esi, dword ptr [eax]
// 006bd42a  897208               mov dword ptr [edx + 8], esi
// 006bd42d  8b30                 mov esi, dword ptr [eax]
// 006bd42f  807e3500             cmp byte ptr [esi + 0x35], 0
// 006bd433  7503                 jne 0x6bd438
// 006bd435  895604               mov dword ptr [esi + 4], edx
// 006bd438  8b7204               mov esi, dword ptr [edx + 4]
// 006bd43b  897004               mov dword ptr [eax + 4], esi
// 006bd43e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006bd441  5e                   pop esi
// 006bd442  3b5104               cmp edx, dword ptr [ecx + 4]
// 006bd445  750b                 jne 0x6bd452
// 006bd447  894104               mov dword ptr [ecx + 4], eax
// 006bd44a  8910                 mov dword ptr [eax], edx
// 006bd44c  894204               mov dword ptr [edx + 4], eax
// 006bd44f  c20400               ret 4
// 006bd452  8b4a04               mov ecx, dword ptr [edx + 4]
// 006bd455  3b11                 cmp edx, dword ptr [ecx]
// 006bd457  750a                 jne 0x6bd463
// 006bd459  8901                 mov dword ptr [ecx], eax
// 006bd45b  8910                 mov dword ptr [eax], edx
// 006bd45d  894204               mov dword ptr [edx + 4], eax
// 006bd460  c20400               ret 4
// 006bd463  894108               mov dword ptr [ecx + 8], eax
// 006bd466  8910                 mov dword ptr [eax], edx
// 006bd468  894204               mov dword ptr [edx + 4], eax
// 006bd46b  c20400               ret 4
// standard library set<pod40> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

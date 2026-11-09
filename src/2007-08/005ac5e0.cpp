// from server: 100% by auto
// roc 2007-08 005ac5e0  unit: RBX::World  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ac5e0
//
// 005ac5e0  8b542404             mov edx, dword ptr [esp + 4]
// 005ac5e4  8b4208               mov eax, dword ptr [edx + 8]
// 005ac5e7  56                   push esi
// 005ac5e8  8b30                 mov esi, dword ptr [eax]
// 005ac5ea  897208               mov dword ptr [edx + 8], esi
// 005ac5ed  8b30                 mov esi, dword ptr [eax]
// 005ac5ef  807e1100             cmp byte ptr [esi + 0x11], 0
// 005ac5f3  7503                 jne 0x5ac5f8
// 005ac5f5  895604               mov dword ptr [esi + 4], edx
// 005ac5f8  8b7204               mov esi, dword ptr [edx + 4]
// 005ac5fb  897004               mov dword ptr [eax + 4], esi
// 005ac5fe  8b4904               mov ecx, dword ptr [ecx + 4]
// 005ac601  3b5104               cmp edx, dword ptr [ecx + 4]
// 005ac604  5e                   pop esi
// 005ac605  750b                 jne 0x5ac612
// 005ac607  894104               mov dword ptr [ecx + 4], eax
// 005ac60a  8910                 mov dword ptr [eax], edx
// 005ac60c  894204               mov dword ptr [edx + 4], eax
// 005ac60f  c20400               ret 4
// 005ac612  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ac615  3b11                 cmp edx, dword ptr [ecx]
// 005ac617  750a                 jne 0x5ac623
// 005ac619  8901                 mov dword ptr [ecx], eax
// 005ac61b  8910                 mov dword ptr [eax], edx
// 005ac61d  894204               mov dword ptr [edx + 4], eax
// 005ac620  c20400               ret 4
// 005ac623  894108               mov dword ptr [ecx + 8], eax
// 005ac626  8910                 mov dword ptr [eax], edx
// 005ac628  894204               mov dword ptr [edx + 4], eax
// 005ac62b  c20400               ret 4
// standard library set<ptr> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

// from server: 100% by auto
// roc 2009-06 0041d7e0  unit: CRobloxTreeCtrl  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041d7e0
//
// 0041d7e0  8b542404             mov edx, dword ptr [esp + 4]
// 0041d7e4  8b4208               mov eax, dword ptr [edx + 8]
// 0041d7e7  56                   push esi
// 0041d7e8  8b30                 mov esi, dword ptr [eax]
// 0041d7ea  897208               mov dword ptr [edx + 8], esi
// 0041d7ed  8b30                 mov esi, dword ptr [eax]
// 0041d7ef  807e1100             cmp byte ptr [esi + 0x11], 0
// 0041d7f3  7503                 jne 0x41d7f8
// 0041d7f5  895604               mov dword ptr [esi + 4], edx
// 0041d7f8  8b7204               mov esi, dword ptr [edx + 4]
// 0041d7fb  897004               mov dword ptr [eax + 4], esi
// 0041d7fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0041d801  5e                   pop esi
// 0041d802  3b5104               cmp edx, dword ptr [ecx + 4]
// 0041d805  750b                 jne 0x41d812
// 0041d807  894104               mov dword ptr [ecx + 4], eax
// 0041d80a  8910                 mov dword ptr [eax], edx
// 0041d80c  894204               mov dword ptr [edx + 4], eax
// 0041d80f  c20400               ret 4
// 0041d812  8b4a04               mov ecx, dword ptr [edx + 4]
// 0041d815  3b11                 cmp edx, dword ptr [ecx]
// 0041d817  750a                 jne 0x41d823
// 0041d819  8901                 mov dword ptr [ecx], eax
// 0041d81b  8910                 mov dword ptr [eax], edx
// 0041d81d  894204               mov dword ptr [edx + 4], eax
// 0041d820  c20400               ret 4
// 0041d823  894108               mov dword ptr [ecx + 8], eax
// 0041d826  8910                 mov dword ptr [eax], edx
// 0041d828  894204               mov dword ptr [edx + 4], eax
// 0041d82b  c20400               ret 4
// standard library set<ptr> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

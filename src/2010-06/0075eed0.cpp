// from server: 100% by auto
// roc 2010-06 0075eed0  unit: RBX::CleanStage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075eed0
//
// 0075eed0  8b542404             mov edx, dword ptr [esp + 4]
// 0075eed4  8b4208               mov eax, dword ptr [edx + 8]
// 0075eed7  56                   push esi
// 0075eed8  8b30                 mov esi, dword ptr [eax]
// 0075eeda  897208               mov dword ptr [edx + 8], esi
// 0075eedd  8b30                 mov esi, dword ptr [eax]
// 0075eedf  807e1100             cmp byte ptr [esi + 0x11], 0
// 0075eee3  7503                 jne 0x75eee8
// 0075eee5  895604               mov dword ptr [esi + 4], edx
// 0075eee8  8b7204               mov esi, dword ptr [edx + 4]
// 0075eeeb  897004               mov dword ptr [eax + 4], esi
// 0075eeee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0075eef1  5e                   pop esi
// 0075eef2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0075eef5  750b                 jne 0x75ef02
// 0075eef7  894104               mov dword ptr [ecx + 4], eax
// 0075eefa  8910                 mov dword ptr [eax], edx
// 0075eefc  894204               mov dword ptr [edx + 4], eax
// 0075eeff  c20400               ret 4
// 0075ef02  8b4a04               mov ecx, dword ptr [edx + 4]
// 0075ef05  3b11                 cmp edx, dword ptr [ecx]
// 0075ef07  750a                 jne 0x75ef13
// 0075ef09  8901                 mov dword ptr [ecx], eax
// 0075ef0b  8910                 mov dword ptr [eax], edx
// 0075ef0d  894204               mov dword ptr [edx + 4], eax
// 0075ef10  c20400               ret 4
// 0075ef13  894108               mov dword ptr [ecx + 8], eax
// 0075ef16  8910                 mov dword ptr [eax], edx
// 0075ef18  894204               mov dword ptr [edx + 4], eax
// 0075ef1b  c20400               ret 4
// standard library set<ptr> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

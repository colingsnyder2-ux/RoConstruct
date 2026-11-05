// from server: 100% by auto
// roc 2010-06 0060d7e0  unit: RBX::Lua::VWeakFunctionRef::?$holder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060d7e0
//
// 0060d7e0  8b542404             mov edx, dword ptr [esp + 4]
// 0060d7e4  8b4208               mov eax, dword ptr [edx + 8]
// 0060d7e7  56                   push esi
// 0060d7e8  8b30                 mov esi, dword ptr [eax]
// 0060d7ea  897208               mov dword ptr [edx + 8], esi
// 0060d7ed  8b30                 mov esi, dword ptr [eax]
// 0060d7ef  807e3900             cmp byte ptr [esi + 0x39], 0
// 0060d7f3  7503                 jne 0x60d7f8
// 0060d7f5  895604               mov dword ptr [esi + 4], edx
// 0060d7f8  8b7204               mov esi, dword ptr [edx + 4]
// 0060d7fb  897004               mov dword ptr [eax + 4], esi
// 0060d7fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0060d801  5e                   pop esi
// 0060d802  3b5104               cmp edx, dword ptr [ecx + 4]
// 0060d805  750b                 jne 0x60d812
// 0060d807  894104               mov dword ptr [ecx + 4], eax
// 0060d80a  8910                 mov dword ptr [eax], edx
// 0060d80c  894204               mov dword ptr [edx + 4], eax
// 0060d80f  c20400               ret 4
// 0060d812  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060d815  3b11                 cmp edx, dword ptr [ecx]
// 0060d817  750a                 jne 0x60d823
// 0060d819  8901                 mov dword ptr [ecx], eax
// 0060d81b  8910                 mov dword ptr [eax], edx
// 0060d81d  894204               mov dword ptr [edx + 4], eax
// 0060d820  c20400               ret 4
// 0060d823  894108               mov dword ptr [ecx + 8], eax
// 0060d826  8910                 mov dword ptr [eax], edx
// 0060d828  894204               mov dword ptr [edx + 4], eax
// 0060d82b  c20400               ret 4
// standard library map_int<pod40> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2009-06 006e21d0  unit: RBX::ScoreHud  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e21d0
//
// 006e21d0  8b542404             mov edx, dword ptr [esp + 4]
// 006e21d4  8b4208               mov eax, dword ptr [edx + 8]
// 006e21d7  56                   push esi
// 006e21d8  8b30                 mov esi, dword ptr [eax]
// 006e21da  897208               mov dword ptr [edx + 8], esi
// 006e21dd  8b30                 mov esi, dword ptr [eax]
// 006e21df  807e2900             cmp byte ptr [esi + 0x29], 0
// 006e21e3  7503                 jne 0x6e21e8
// 006e21e5  895604               mov dword ptr [esi + 4], edx
// 006e21e8  8b7204               mov esi, dword ptr [edx + 4]
// 006e21eb  897004               mov dword ptr [eax + 4], esi
// 006e21ee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006e21f1  5e                   pop esi
// 006e21f2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006e21f5  750b                 jne 0x6e2202
// 006e21f7  894104               mov dword ptr [ecx + 4], eax
// 006e21fa  8910                 mov dword ptr [eax], edx
// 006e21fc  894204               mov dword ptr [edx + 4], eax
// 006e21ff  c20400               ret 4
// 006e2202  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e2205  3b11                 cmp edx, dword ptr [ecx]
// 006e2207  750a                 jne 0x6e2213
// 006e2209  8901                 mov dword ptr [ecx], eax
// 006e220b  8910                 mov dword ptr [eax], edx
// 006e220d  894204               mov dword ptr [edx + 4], eax
// 006e2210  c20400               ret 4
// 006e2213  894108               mov dword ptr [ecx + 8], eax
// 006e2216  8910                 mov dword ptr [eax], edx
// 006e2218  894204               mov dword ptr [edx + 4], eax
// 006e221b  c20400               ret 4
// standard library set<string> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

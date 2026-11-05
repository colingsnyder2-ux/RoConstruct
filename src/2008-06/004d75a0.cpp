// from server: 100% by auto
// roc 2008-06 004d75a0  unit: Ogre::VDataStream::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d75a0
//
// 004d75a0  8b542404             mov edx, dword ptr [esp + 4]
// 004d75a4  8b4208               mov eax, dword ptr [edx + 8]
// 004d75a7  56                   push esi
// 004d75a8  8b30                 mov esi, dword ptr [eax]
// 004d75aa  897208               mov dword ptr [edx + 8], esi
// 004d75ad  8b30                 mov esi, dword ptr [eax]
// 004d75af  807e2900             cmp byte ptr [esi + 0x29], 0
// 004d75b3  7503                 jne 0x4d75b8
// 004d75b5  895604               mov dword ptr [esi + 4], edx
// 004d75b8  8b7204               mov esi, dword ptr [edx + 4]
// 004d75bb  897004               mov dword ptr [eax + 4], esi
// 004d75be  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004d75c1  5e                   pop esi
// 004d75c2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004d75c5  750b                 jne 0x4d75d2
// 004d75c7  894104               mov dword ptr [ecx + 4], eax
// 004d75ca  8910                 mov dword ptr [eax], edx
// 004d75cc  894204               mov dword ptr [edx + 4], eax
// 004d75cf  c20400               ret 4
// 004d75d2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d75d5  3b11                 cmp edx, dword ptr [ecx]
// 004d75d7  750a                 jne 0x4d75e3
// 004d75d9  8901                 mov dword ptr [ecx], eax
// 004d75db  8910                 mov dword ptr [eax], edx
// 004d75dd  894204               mov dword ptr [edx + 4], eax
// 004d75e0  c20400               ret 4
// 004d75e3  894108               mov dword ptr [ecx + 8], eax
// 004d75e6  8910                 mov dword ptr [eax], edx
// 004d75e8  894204               mov dword ptr [edx + 4], eax
// 004d75eb  c20400               ret 4
// standard library set<string> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;

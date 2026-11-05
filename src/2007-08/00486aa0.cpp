// from server: 100% by auto
// roc 2007-08 00486aa0  unit: G3D::GWindow  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00486aa0
//
// 00486aa0  8b542404             mov edx, dword ptr [esp + 4]
// 00486aa4  8b02                 mov eax, dword ptr [edx]
// 00486aa6  56                   push esi
// 00486aa7  8b7008               mov esi, dword ptr [eax + 8]
// 00486aaa  8932                 mov dword ptr [edx], esi
// 00486aac  8b7008               mov esi, dword ptr [eax + 8]
// 00486aaf  807e0e00             cmp byte ptr [esi + 0xe], 0
// 00486ab3  7503                 jne 0x486ab8
// 00486ab5  895604               mov dword ptr [esi + 4], edx
// 00486ab8  8b7204               mov esi, dword ptr [edx + 4]
// 00486abb  897004               mov dword ptr [eax + 4], esi
// 00486abe  8b4904               mov ecx, dword ptr [ecx + 4]
// 00486ac1  3b5104               cmp edx, dword ptr [ecx + 4]
// 00486ac4  5e                   pop esi
// 00486ac5  750c                 jne 0x486ad3
// 00486ac7  894104               mov dword ptr [ecx + 4], eax
// 00486aca  895008               mov dword ptr [eax + 8], edx
// 00486acd  894204               mov dword ptr [edx + 4], eax
// 00486ad0  c20400               ret 4
// 00486ad3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00486ad6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00486ad9  750c                 jne 0x486ae7
// 00486adb  894108               mov dword ptr [ecx + 8], eax
// 00486ade  895008               mov dword ptr [eax + 8], edx
// 00486ae1  894204               mov dword ptr [edx + 4], eax
// 00486ae4  c20400               ret 4
// 00486ae7  8901                 mov dword ptr [ecx], eax
// 00486ae9  895008               mov dword ptr [eax + 8], edx
// 00486aec  894204               mov dword ptr [edx + 4], eax
// 00486aef  c20400               ret 4
// standard library set<char> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;

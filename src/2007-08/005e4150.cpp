// from server: 100% by auto
// roc 2007-08 005e4150  unit: RBX::ArrowTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e4150
//
// 005e4150  8b542404             mov edx, dword ptr [esp + 4]
// 005e4154  8b02                 mov eax, dword ptr [edx]
// 005e4156  56                   push esi
// 005e4157  8b7008               mov esi, dword ptr [eax + 8]
// 005e415a  8932                 mov dword ptr [edx], esi
// 005e415c  8b7008               mov esi, dword ptr [eax + 8]
// 005e415f  807e1100             cmp byte ptr [esi + 0x11], 0
// 005e4163  7503                 jne 0x5e4168
// 005e4165  895604               mov dword ptr [esi + 4], edx
// 005e4168  8b7204               mov esi, dword ptr [edx + 4]
// 005e416b  897004               mov dword ptr [eax + 4], esi
// 005e416e  8b4904               mov ecx, dword ptr [ecx + 4]
// 005e4171  3b5104               cmp edx, dword ptr [ecx + 4]
// 005e4174  5e                   pop esi
// 005e4175  750c                 jne 0x5e4183
// 005e4177  894104               mov dword ptr [ecx + 4], eax
// 005e417a  895008               mov dword ptr [eax + 8], edx
// 005e417d  894204               mov dword ptr [edx + 4], eax
// 005e4180  c20400               ret 4
// 005e4183  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e4186  3b5108               cmp edx, dword ptr [ecx + 8]
// 005e4189  750c                 jne 0x5e4197
// 005e418b  894108               mov dword ptr [ecx + 8], eax
// 005e418e  895008               mov dword ptr [eax + 8], edx
// 005e4191  894204               mov dword ptr [edx + 4], eax
// 005e4194  c20400               ret 4
// 005e4197  8901                 mov dword ptr [ecx], eax
// 005e4199  895008               mov dword ptr [eax + 8], edx
// 005e419c  894204               mov dword ptr [edx + 4], eax
// 005e419f  c20400               ret 4
// standard library set<ptr> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

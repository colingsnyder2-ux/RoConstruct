// from server: 100% by auto
// roc 2008-06 0068d0a0  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d0a0
//
// 0068d0a0  8b542404             mov edx, dword ptr [esp + 4]
// 0068d0a4  8b02                 mov eax, dword ptr [edx]
// 0068d0a6  56                   push esi
// 0068d0a7  8b7008               mov esi, dword ptr [eax + 8]
// 0068d0aa  8932                 mov dword ptr [edx], esi
// 0068d0ac  8b7008               mov esi, dword ptr [eax + 8]
// 0068d0af  807e1100             cmp byte ptr [esi + 0x11], 0
// 0068d0b3  7503                 jne 0x68d0b8
// 0068d0b5  895604               mov dword ptr [esi + 4], edx
// 0068d0b8  8b7204               mov esi, dword ptr [edx + 4]
// 0068d0bb  897004               mov dword ptr [eax + 4], esi
// 0068d0be  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0068d0c1  5e                   pop esi
// 0068d0c2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0068d0c5  750c                 jne 0x68d0d3
// 0068d0c7  894104               mov dword ptr [ecx + 4], eax
// 0068d0ca  895008               mov dword ptr [eax + 8], edx
// 0068d0cd  894204               mov dword ptr [edx + 4], eax
// 0068d0d0  c20400               ret 4
// 0068d0d3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068d0d6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0068d0d9  750c                 jne 0x68d0e7
// 0068d0db  894108               mov dword ptr [ecx + 8], eax
// 0068d0de  895008               mov dword ptr [eax + 8], edx
// 0068d0e1  894204               mov dword ptr [edx + 4], eax
// 0068d0e4  c20400               ret 4
// 0068d0e7  8901                 mov dword ptr [ecx], eax
// 0068d0e9  895008               mov dword ptr [eax + 8], edx
// 0068d0ec  894204               mov dword ptr [edx + 4], eax
// 0068d0ef  c20400               ret 4
// standard library set<ptr> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

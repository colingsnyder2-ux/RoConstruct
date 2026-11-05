// from server: 100% by auto
// roc 2008-06 0068d140  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d140
//
// 0068d140  8b542404             mov edx, dword ptr [esp + 4]
// 0068d144  8b02                 mov eax, dword ptr [edx]
// 0068d146  56                   push esi
// 0068d147  8b7008               mov esi, dword ptr [eax + 8]
// 0068d14a  8932                 mov dword ptr [edx], esi
// 0068d14c  8b7008               mov esi, dword ptr [eax + 8]
// 0068d14f  807e3900             cmp byte ptr [esi + 0x39], 0
// 0068d153  7503                 jne 0x68d158
// 0068d155  895604               mov dword ptr [esi + 4], edx
// 0068d158  8b7204               mov esi, dword ptr [edx + 4]
// 0068d15b  897004               mov dword ptr [eax + 4], esi
// 0068d15e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0068d161  5e                   pop esi
// 0068d162  3b5104               cmp edx, dword ptr [ecx + 4]
// 0068d165  750c                 jne 0x68d173
// 0068d167  894104               mov dword ptr [ecx + 4], eax
// 0068d16a  895008               mov dword ptr [eax + 8], edx
// 0068d16d  894204               mov dword ptr [edx + 4], eax
// 0068d170  c20400               ret 4
// 0068d173  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068d176  3b5108               cmp edx, dword ptr [ecx + 8]
// 0068d179  750c                 jne 0x68d187
// 0068d17b  894108               mov dword ptr [ecx + 8], eax
// 0068d17e  895008               mov dword ptr [eax + 8], edx
// 0068d181  894204               mov dword ptr [edx + 4], eax
// 0068d184  c20400               ret 4
// 0068d187  8901                 mov dword ptr [ecx], eax
// 0068d189  895008               mov dword ptr [eax + 8], edx
// 0068d18c  894204               mov dword ptr [edx + 4], eax
// 0068d18f  c20400               ret 4
// standard library map_int<pod40> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

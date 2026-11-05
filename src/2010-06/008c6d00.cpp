// from server: 100% by auto
// roc 2010-06 008c6d00  unit: Ogre::VRbxFont::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6d00
//
// 008c6d00  8b542404             mov edx, dword ptr [esp + 4]
// 008c6d04  8b02                 mov eax, dword ptr [edx]
// 008c6d06  56                   push esi
// 008c6d07  8b7008               mov esi, dword ptr [eax + 8]
// 008c6d0a  8932                 mov dword ptr [edx], esi
// 008c6d0c  8b7008               mov esi, dword ptr [eax + 8]
// 008c6d0f  807e3900             cmp byte ptr [esi + 0x39], 0
// 008c6d13  7503                 jne 0x8c6d18
// 008c6d15  895604               mov dword ptr [esi + 4], edx
// 008c6d18  8b7204               mov esi, dword ptr [edx + 4]
// 008c6d1b  897004               mov dword ptr [eax + 4], esi
// 008c6d1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 008c6d21  5e                   pop esi
// 008c6d22  3b5104               cmp edx, dword ptr [ecx + 4]
// 008c6d25  750c                 jne 0x8c6d33
// 008c6d27  894104               mov dword ptr [ecx + 4], eax
// 008c6d2a  895008               mov dword ptr [eax + 8], edx
// 008c6d2d  894204               mov dword ptr [edx + 4], eax
// 008c6d30  c20400               ret 4
// 008c6d33  8b4a04               mov ecx, dword ptr [edx + 4]
// 008c6d36  3b5108               cmp edx, dword ptr [ecx + 8]
// 008c6d39  750c                 jne 0x8c6d47
// 008c6d3b  894108               mov dword ptr [ecx + 8], eax
// 008c6d3e  895008               mov dword ptr [eax + 8], edx
// 008c6d41  894204               mov dword ptr [edx + 4], eax
// 008c6d44  c20400               ret 4
// 008c6d47  8901                 mov dword ptr [ecx], eax
// 008c6d49  895008               mov dword ptr [eax + 8], edx
// 008c6d4c  894204               mov dword ptr [edx + 4], eax
// 008c6d4f  c20400               ret 4
// standard library map_int<pod40> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

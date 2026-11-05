// from server: 100% by auto
// roc 2008-06 0068df50  unit: Ogre::VRbxSky::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068df50
//
// 0068df50  8b542404             mov edx, dword ptr [esp + 4]
// 0068df54  8b4208               mov eax, dword ptr [edx + 8]
// 0068df57  56                   push esi
// 0068df58  8b30                 mov esi, dword ptr [eax]
// 0068df5a  897208               mov dword ptr [edx + 8], esi
// 0068df5d  8b30                 mov esi, dword ptr [eax]
// 0068df5f  807e3900             cmp byte ptr [esi + 0x39], 0
// 0068df63  7503                 jne 0x68df68
// 0068df65  895604               mov dword ptr [esi + 4], edx
// 0068df68  8b7204               mov esi, dword ptr [edx + 4]
// 0068df6b  897004               mov dword ptr [eax + 4], esi
// 0068df6e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0068df71  5e                   pop esi
// 0068df72  3b5104               cmp edx, dword ptr [ecx + 4]
// 0068df75  750b                 jne 0x68df82
// 0068df77  894104               mov dword ptr [ecx + 4], eax
// 0068df7a  8910                 mov dword ptr [eax], edx
// 0068df7c  894204               mov dword ptr [edx + 4], eax
// 0068df7f  c20400               ret 4
// 0068df82  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068df85  3b11                 cmp edx, dword ptr [ecx]
// 0068df87  750a                 jne 0x68df93
// 0068df89  8901                 mov dword ptr [ecx], eax
// 0068df8b  8910                 mov dword ptr [eax], edx
// 0068df8d  894204               mov dword ptr [edx + 4], eax
// 0068df90  c20400               ret 4
// 0068df93  894108               mov dword ptr [ecx + 8], eax
// 0068df96  8910                 mov dword ptr [eax], edx
// 0068df98  894204               mov dword ptr [edx + 4], eax
// 0068df9b  c20400               ret 4
// standard library map_int<pod40> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

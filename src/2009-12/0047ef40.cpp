// from server: 100% by auto
// roc 2009-12 0047ef40  unit: Ogre::VRbxFont::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ef40
//
// 0047ef40  8b542404             mov edx, dword ptr [esp + 4]
// 0047ef44  8b4208               mov eax, dword ptr [edx + 8]
// 0047ef47  56                   push esi
// 0047ef48  8b30                 mov esi, dword ptr [eax]
// 0047ef4a  897208               mov dword ptr [edx + 8], esi
// 0047ef4d  8b30                 mov esi, dword ptr [eax]
// 0047ef4f  807e3900             cmp byte ptr [esi + 0x39], 0
// 0047ef53  7503                 jne 0x47ef58
// 0047ef55  895604               mov dword ptr [esi + 4], edx
// 0047ef58  8b7204               mov esi, dword ptr [edx + 4]
// 0047ef5b  897004               mov dword ptr [eax + 4], esi
// 0047ef5e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0047ef61  5e                   pop esi
// 0047ef62  3b5104               cmp edx, dword ptr [ecx + 4]
// 0047ef65  750b                 jne 0x47ef72
// 0047ef67  894104               mov dword ptr [ecx + 4], eax
// 0047ef6a  8910                 mov dword ptr [eax], edx
// 0047ef6c  894204               mov dword ptr [edx + 4], eax
// 0047ef6f  c20400               ret 4
// 0047ef72  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047ef75  3b11                 cmp edx, dword ptr [ecx]
// 0047ef77  750a                 jne 0x47ef83
// 0047ef79  8901                 mov dword ptr [ecx], eax
// 0047ef7b  8910                 mov dword ptr [eax], edx
// 0047ef7d  894204               mov dword ptr [edx + 4], eax
// 0047ef80  c20400               ret 4
// 0047ef83  894108               mov dword ptr [ecx + 8], eax
// 0047ef86  8910                 mov dword ptr [eax], edx
// 0047ef88  894204               mov dword ptr [edx + 4], eax
// 0047ef8b  c20400               ret 4
// standard library map_int<pod40> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

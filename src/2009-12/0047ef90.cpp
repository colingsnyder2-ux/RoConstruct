// from server: 100% by auto
// roc 2009-12 0047ef90  unit: Ogre::VRbxFont::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ef90
//
// 0047ef90  8b542404             mov edx, dword ptr [esp + 4]
// 0047ef94  8b02                 mov eax, dword ptr [edx]
// 0047ef96  56                   push esi
// 0047ef97  8b7008               mov esi, dword ptr [eax + 8]
// 0047ef9a  8932                 mov dword ptr [edx], esi
// 0047ef9c  8b7008               mov esi, dword ptr [eax + 8]
// 0047ef9f  807e3900             cmp byte ptr [esi + 0x39], 0
// 0047efa3  7503                 jne 0x47efa8
// 0047efa5  895604               mov dword ptr [esi + 4], edx
// 0047efa8  8b7204               mov esi, dword ptr [edx + 4]
// 0047efab  897004               mov dword ptr [eax + 4], esi
// 0047efae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0047efb1  5e                   pop esi
// 0047efb2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0047efb5  750c                 jne 0x47efc3
// 0047efb7  894104               mov dword ptr [ecx + 4], eax
// 0047efba  895008               mov dword ptr [eax + 8], edx
// 0047efbd  894204               mov dword ptr [edx + 4], eax
// 0047efc0  c20400               ret 4
// 0047efc3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047efc6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0047efc9  750c                 jne 0x47efd7
// 0047efcb  894108               mov dword ptr [ecx + 8], eax
// 0047efce  895008               mov dword ptr [eax + 8], edx
// 0047efd1  894204               mov dword ptr [edx + 4], eax
// 0047efd4  c20400               ret 4
// 0047efd7  8901                 mov dword ptr [ecx], eax
// 0047efd9  895008               mov dword ptr [eax + 8], edx
// 0047efdc  894204               mov dword ptr [edx + 4], eax
// 0047efdf  c20400               ret 4
// standard library map_int<pod40> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

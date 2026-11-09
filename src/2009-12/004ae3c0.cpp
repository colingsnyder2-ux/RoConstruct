// from server: 100% by auto
// roc 2009-12 004ae3c0  unit: Ogre::RbxManualTextureLoader  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae3c0
//
// 004ae3c0  8b542404             mov edx, dword ptr [esp + 4]
// 004ae3c4  8b4208               mov eax, dword ptr [edx + 8]
// 004ae3c7  56                   push esi
// 004ae3c8  8b30                 mov esi, dword ptr [eax]
// 004ae3ca  897208               mov dword ptr [edx + 8], esi
// 004ae3cd  8b30                 mov esi, dword ptr [eax]
// 004ae3cf  807e6900             cmp byte ptr [esi + 0x69], 0
// 004ae3d3  7503                 jne 0x4ae3d8
// 004ae3d5  895604               mov dword ptr [esi + 4], edx
// 004ae3d8  8b7204               mov esi, dword ptr [edx + 4]
// 004ae3db  897004               mov dword ptr [eax + 4], esi
// 004ae3de  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004ae3e1  5e                   pop esi
// 004ae3e2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004ae3e5  750b                 jne 0x4ae3f2
// 004ae3e7  894104               mov dword ptr [ecx + 4], eax
// 004ae3ea  8910                 mov dword ptr [eax], edx
// 004ae3ec  894204               mov dword ptr [edx + 4], eax
// 004ae3ef  c20400               ret 4
// 004ae3f2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae3f5  3b11                 cmp edx, dword ptr [ecx]
// 004ae3f7  750a                 jne 0x4ae403
// 004ae3f9  8901                 mov dword ptr [ecx], eax
// 004ae3fb  8910                 mov dword ptr [eax], edx
// 004ae3fd  894204               mov dword ptr [edx + 4], eax
// 004ae400  c20400               ret 4
// 004ae403  894108               mov dword ptr [ecx + 8], eax
// 004ae406  8910                 mov dword ptr [eax], edx
// 004ae408  894204               mov dword ptr [edx + 4], eax
// 004ae40b  c20400               ret 4
// standard library map_str<pod64> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

// from server: 100% by auto
// roc 2009-12 004ae0d0  unit: Ogre::RbxManualTextureLoader  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae0d0
//
// 004ae0d0  8b542404             mov edx, dword ptr [esp + 4]
// 004ae0d4  8b02                 mov eax, dword ptr [edx]
// 004ae0d6  56                   push esi
// 004ae0d7  8b7008               mov esi, dword ptr [eax + 8]
// 004ae0da  8932                 mov dword ptr [edx], esi
// 004ae0dc  8b7008               mov esi, dword ptr [eax + 8]
// 004ae0df  807e6900             cmp byte ptr [esi + 0x69], 0
// 004ae0e3  7503                 jne 0x4ae0e8
// 004ae0e5  895604               mov dword ptr [esi + 4], edx
// 004ae0e8  8b7204               mov esi, dword ptr [edx + 4]
// 004ae0eb  897004               mov dword ptr [eax + 4], esi
// 004ae0ee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004ae0f1  5e                   pop esi
// 004ae0f2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004ae0f5  750c                 jne 0x4ae103
// 004ae0f7  894104               mov dword ptr [ecx + 4], eax
// 004ae0fa  895008               mov dword ptr [eax + 8], edx
// 004ae0fd  894204               mov dword ptr [edx + 4], eax
// 004ae100  c20400               ret 4
// 004ae103  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae106  3b5108               cmp edx, dword ptr [ecx + 8]
// 004ae109  750c                 jne 0x4ae117
// 004ae10b  894108               mov dword ptr [ecx + 8], eax
// 004ae10e  895008               mov dword ptr [eax + 8], edx
// 004ae111  894204               mov dword ptr [edx + 4], eax
// 004ae114  c20400               ret 4
// 004ae117  8901                 mov dword ptr [ecx], eax
// 004ae119  895008               mov dword ptr [eax + 8], edx
// 004ae11c  894204               mov dword ptr [edx + 4], eax
// 004ae11f  c20400               ret 4
// standard library map_str<pod64> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

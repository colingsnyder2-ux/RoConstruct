// from server: 100% by auto
// roc 2009-06 0048bbc0  unit: Ogre::RbxManualTextureLoader  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048bbc0
//
// 0048bbc0  8b542404             mov edx, dword ptr [esp + 4]
// 0048bbc4  8b4208               mov eax, dword ptr [edx + 8]
// 0048bbc7  56                   push esi
// 0048bbc8  8b30                 mov esi, dword ptr [eax]
// 0048bbca  897208               mov dword ptr [edx + 8], esi
// 0048bbcd  8b30                 mov esi, dword ptr [eax]
// 0048bbcf  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048bbd3  7503                 jne 0x48bbd8
// 0048bbd5  895604               mov dword ptr [esi + 4], edx
// 0048bbd8  8b7204               mov esi, dword ptr [edx + 4]
// 0048bbdb  897004               mov dword ptr [eax + 4], esi
// 0048bbde  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0048bbe1  5e                   pop esi
// 0048bbe2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0048bbe5  750b                 jne 0x48bbf2
// 0048bbe7  894104               mov dword ptr [ecx + 4], eax
// 0048bbea  8910                 mov dword ptr [eax], edx
// 0048bbec  894204               mov dword ptr [edx + 4], eax
// 0048bbef  c20400               ret 4
// 0048bbf2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048bbf5  3b11                 cmp edx, dword ptr [ecx]
// 0048bbf7  750a                 jne 0x48bc03
// 0048bbf9  8901                 mov dword ptr [ecx], eax
// 0048bbfb  8910                 mov dword ptr [eax], edx
// 0048bbfd  894204               mov dword ptr [edx + 4], eax
// 0048bc00  c20400               ret 4
// 0048bc03  894108               mov dword ptr [ecx + 8], eax
// 0048bc06  8910                 mov dword ptr [eax], edx
// 0048bc08  894204               mov dword ptr [edx + 4], eax
// 0048bc0b  c20400               ret 4
// standard library map_str<pod64> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

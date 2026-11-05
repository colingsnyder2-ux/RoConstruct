// from server: 100% by auto
// roc 2009-06 0048b740  unit: Ogre::RbxManualTextureLoader  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b740
//
// 0048b740  8b542404             mov edx, dword ptr [esp + 4]
// 0048b744  8b02                 mov eax, dword ptr [edx]
// 0048b746  56                   push esi
// 0048b747  8b7008               mov esi, dword ptr [eax + 8]
// 0048b74a  8932                 mov dword ptr [edx], esi
// 0048b74c  8b7008               mov esi, dword ptr [eax + 8]
// 0048b74f  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048b753  7503                 jne 0x48b758
// 0048b755  895604               mov dword ptr [esi + 4], edx
// 0048b758  8b7204               mov esi, dword ptr [edx + 4]
// 0048b75b  897004               mov dword ptr [eax + 4], esi
// 0048b75e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0048b761  5e                   pop esi
// 0048b762  3b5104               cmp edx, dword ptr [ecx + 4]
// 0048b765  750c                 jne 0x48b773
// 0048b767  894104               mov dword ptr [ecx + 4], eax
// 0048b76a  895008               mov dword ptr [eax + 8], edx
// 0048b76d  894204               mov dword ptr [edx + 4], eax
// 0048b770  c20400               ret 4
// 0048b773  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048b776  3b5108               cmp edx, dword ptr [ecx + 8]
// 0048b779  750c                 jne 0x48b787
// 0048b77b  894108               mov dword ptr [ecx + 8], eax
// 0048b77e  895008               mov dword ptr [eax + 8], edx
// 0048b781  894204               mov dword ptr [edx + 4], eax
// 0048b784  c20400               ret 4
// 0048b787  8901                 mov dword ptr [ecx], eax
// 0048b789  895008               mov dword ptr [eax + 8], edx
// 0048b78c  894204               mov dword ptr [edx + 4], eax
// 0048b78f  c20400               ret 4
// standard library map_str<pod64> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

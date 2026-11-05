// from server: 100% by auto
// roc 2009-06 00618310  unit: RBX::Script  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618310
//
// 00618310  8b542404             mov edx, dword ptr [esp + 4]
// 00618314  8b02                 mov eax, dword ptr [edx]
// 00618316  56                   push esi
// 00618317  8b7008               mov esi, dword ptr [eax + 8]
// 0061831a  8932                 mov dword ptr [edx], esi
// 0061831c  8b7008               mov esi, dword ptr [eax + 8]
// 0061831f  807e4900             cmp byte ptr [esi + 0x49], 0
// 00618323  7503                 jne 0x618328
// 00618325  895604               mov dword ptr [esi + 4], edx
// 00618328  8b7204               mov esi, dword ptr [edx + 4]
// 0061832b  897004               mov dword ptr [eax + 4], esi
// 0061832e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00618331  5e                   pop esi
// 00618332  3b5104               cmp edx, dword ptr [ecx + 4]
// 00618335  750c                 jne 0x618343
// 00618337  894104               mov dword ptr [ecx + 4], eax
// 0061833a  895008               mov dword ptr [eax + 8], edx
// 0061833d  894204               mov dword ptr [edx + 4], eax
// 00618340  c20400               ret 4
// 00618343  8b4a04               mov ecx, dword ptr [edx + 4]
// 00618346  3b5108               cmp edx, dword ptr [ecx + 8]
// 00618349  750c                 jne 0x618357
// 0061834b  894108               mov dword ptr [ecx + 8], eax
// 0061834e  895008               mov dword ptr [eax + 8], edx
// 00618351  894204               mov dword ptr [edx + 4], eax
// 00618354  c20400               ret 4
// 00618357  8901                 mov dword ptr [ecx], eax
// 00618359  895008               mov dword ptr [eax + 8], edx
// 0061835c  894204               mov dword ptr [edx + 4], eax
// 0061835f  c20400               ret 4
// standard library map_str<pod32> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

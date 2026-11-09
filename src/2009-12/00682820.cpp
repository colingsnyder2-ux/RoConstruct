// from server: 100% by auto
// roc 2009-12 00682820  unit: RBX::Script  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682820
//
// 00682820  8b542404             mov edx, dword ptr [esp + 4]
// 00682824  8b02                 mov eax, dword ptr [edx]
// 00682826  56                   push esi
// 00682827  8b7008               mov esi, dword ptr [eax + 8]
// 0068282a  8932                 mov dword ptr [edx], esi
// 0068282c  8b7008               mov esi, dword ptr [eax + 8]
// 0068282f  807e4900             cmp byte ptr [esi + 0x49], 0
// 00682833  7503                 jne 0x682838
// 00682835  895604               mov dword ptr [esi + 4], edx
// 00682838  8b7204               mov esi, dword ptr [edx + 4]
// 0068283b  897004               mov dword ptr [eax + 4], esi
// 0068283e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00682841  5e                   pop esi
// 00682842  3b5104               cmp edx, dword ptr [ecx + 4]
// 00682845  750c                 jne 0x682853
// 00682847  894104               mov dword ptr [ecx + 4], eax
// 0068284a  895008               mov dword ptr [eax + 8], edx
// 0068284d  894204               mov dword ptr [edx + 4], eax
// 00682850  c20400               ret 4
// 00682853  8b4a04               mov ecx, dword ptr [edx + 4]
// 00682856  3b5108               cmp edx, dword ptr [ecx + 8]
// 00682859  750c                 jne 0x682867
// 0068285b  894108               mov dword ptr [ecx + 8], eax
// 0068285e  895008               mov dword ptr [eax + 8], edx
// 00682861  894204               mov dword ptr [edx + 4], eax
// 00682864  c20400               ret 4
// 00682867  8901                 mov dword ptr [ecx], eax
// 00682869  895008               mov dword ptr [eax + 8], edx
// 0068286c  894204               mov dword ptr [edx + 4], eax
// 0068286f  c20400               ret 4
// standard library map_str<pod32> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;

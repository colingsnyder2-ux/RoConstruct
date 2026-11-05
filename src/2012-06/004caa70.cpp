// from server: 100% by auto
// roc 2012-06 004caa70  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004caa70
//
// 004caa70  6a40                 push 0x40
// 004caa72  e8a3764b00           call 0x98211a
// 004caa77  83c404               add esp, 4
// 004caa7a  85c0                 test eax, eax
// 004caa7c  7406                 je 0x4caa84
// 004caa7e  c70000000000         mov dword ptr [eax], 0
// 004caa84  8d4804               lea ecx, [eax + 4]
// 004caa87  85c9                 test ecx, ecx
// 004caa89  7406                 je 0x4caa91
// 004caa8b  c70100000000         mov dword ptr [ecx], 0
// 004caa91  8d4808               lea ecx, [eax + 8]
// 004caa94  85c9                 test ecx, ecx
// 004caa96  7406                 je 0x4caa9e
// 004caa98  c70100000000         mov dword ptr [ecx], 0
// 004caa9e  c6403801             mov byte ptr [eax + 0x38], 1
// 004caaa2  c6403900             mov byte ptr [eax + 0x39], 0
// 004caaa6  c3                   ret 
// standard library map_str<double> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<double>
typedef double E;
#include <map>
#include <string>
template class std::map<std::string, E>;

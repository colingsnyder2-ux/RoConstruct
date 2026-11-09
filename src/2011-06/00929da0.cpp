// from server: 100% by auto
// roc 2011-06 00929da0  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929da0
//
// 00929da0  6a40                 push 0x40
// 00929da2  e8b702eeff           call 0x80a05e
// 00929da7  83c404               add esp, 4
// 00929daa  85c0                 test eax, eax
// 00929dac  7406                 je 0x929db4
// 00929dae  c70000000000         mov dword ptr [eax], 0
// 00929db4  8d4804               lea ecx, [eax + 4]
// 00929db7  85c9                 test ecx, ecx
// 00929db9  7406                 je 0x929dc1
// 00929dbb  c70100000000         mov dword ptr [ecx], 0
// 00929dc1  8d4808               lea ecx, [eax + 8]
// 00929dc4  85c9                 test ecx, ecx
// 00929dc6  7406                 je 0x929dce
// 00929dc8  c70100000000         mov dword ptr [ecx], 0
// 00929dce  c6403801             mov byte ptr [eax + 0x38], 1
// 00929dd2  c6403900             mov byte ptr [eax + 0x39], 0
// 00929dd6  c3                   ret 
// standard library map_str<double> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<double>
typedef double E;
#include <map>
#include <string>
template class std::map<std::string, E>;

// from server: 100% by auto
// roc 2012-06 0090d8d0  unit: RBX::WedgePoly  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0090d8d0
//
// 0090d8d0  6a20                 push 0x20
// 0090d8d2  e843480700           call 0x98211a
// 0090d8d7  83c404               add esp, 4
// 0090d8da  85c0                 test eax, eax
// 0090d8dc  743a                 je 0x90d918
// 0090d8de  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0090d8e2  8b542408             mov edx, dword ptr [esp + 8]
// 0090d8e6  8908                 mov dword ptr [eax], ecx
// 0090d8e8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0090d8ec  894808               mov dword ptr [eax + 8], ecx
// 0090d8ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0090d8f3  895004               mov dword ptr [eax + 4], edx
// 0090d8f6  8b11                 mov edx, dword ptr [ecx]
// 0090d8f8  89500c               mov dword ptr [eax + 0xc], edx
// 0090d8fb  8b5104               mov edx, dword ptr [ecx + 4]
// 0090d8fe  895010               mov dword ptr [eax + 0x10], edx
// 0090d901  8b5108               mov edx, dword ptr [ecx + 8]
// 0090d904  895014               mov dword ptr [eax + 0x14], edx
// 0090d907  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0090d90a  8a542414             mov dl, byte ptr [esp + 0x14]
// 0090d90e  894818               mov dword ptr [eax + 0x18], ecx
// 0090d911  88501c               mov byte ptr [eax + 0x1c], dl
// 0090d914  c6401d00             mov byte ptr [eax + 0x1d], 0
// 0090d918  c21400               ret 0x14
// standard library map_int<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;

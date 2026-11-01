// from server: 100% by auto
// roc 2009-12 00539680  unit: G3D::VRay::?$holder  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00539680
//
// 00539680  6a1c                 push 0x1c
// 00539682  e8d9a12b00           call 0x7f3860
// 00539687  83c404               add esp, 4
// 0053968a  85c0                 test eax, eax
// 0053968c  7434                 je 0x5396c2
// 0053968e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00539692  8b542408             mov edx, dword ptr [esp + 8]
// 00539696  8908                 mov dword ptr [eax], ecx
// 00539698  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0053969c  894808               mov dword ptr [eax + 8], ecx
// 0053969f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005396a3  895004               mov dword ptr [eax + 4], edx
// 005396a6  8b11                 mov edx, dword ptr [ecx]
// 005396a8  89500c               mov dword ptr [eax + 0xc], edx
// 005396ab  8b5104               mov edx, dword ptr [ecx + 4]
// 005396ae  895010               mov dword ptr [eax + 0x10], edx
// 005396b1  8b4908               mov ecx, dword ptr [ecx + 8]
// 005396b4  8a542414             mov dl, byte ptr [esp + 0x14]
// 005396b8  894814               mov dword ptr [eax + 0x14], ecx
// 005396bb  885018               mov byte ptr [eax + 0x18], dl
// 005396be  c6401900             mov byte ptr [eax + 0x19], 0
// 005396c2  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

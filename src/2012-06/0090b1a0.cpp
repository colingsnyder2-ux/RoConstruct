// from server: 100% by auto
// roc 2012-06 0090b1a0  unit: RBX::PrismPoly  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0090b1a0
//
// 0090b1a0  6a28                 push 0x28
// 0090b1a2  e8736f0700           call 0x98211a
// 0090b1a7  83c404               add esp, 4
// 0090b1aa  85c0                 test eax, eax
// 0090b1ac  7446                 je 0x90b1f4
// 0090b1ae  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0090b1b2  8b542408             mov edx, dword ptr [esp + 8]
// 0090b1b6  8908                 mov dword ptr [eax], ecx
// 0090b1b8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0090b1bc  894808               mov dword ptr [eax + 8], ecx
// 0090b1bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0090b1c3  895004               mov dword ptr [eax + 4], edx
// 0090b1c6  8b11                 mov edx, dword ptr [ecx]
// 0090b1c8  89500c               mov dword ptr [eax + 0xc], edx
// 0090b1cb  8b5104               mov edx, dword ptr [ecx + 4]
// 0090b1ce  895010               mov dword ptr [eax + 0x10], edx
// 0090b1d1  8b5108               mov edx, dword ptr [ecx + 8]
// 0090b1d4  895014               mov dword ptr [eax + 0x14], edx
// 0090b1d7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0090b1da  895018               mov dword ptr [eax + 0x18], edx
// 0090b1dd  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0090b1e0  89501c               mov dword ptr [eax + 0x1c], edx
// 0090b1e3  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0090b1e6  8a542414             mov dl, byte ptr [esp + 0x14]
// 0090b1ea  894820               mov dword ptr [eax + 0x20], ecx
// 0090b1ed  885024               mov byte ptr [eax + 0x24], dl
// 0090b1f0  c6402500             mov byte ptr [eax + 0x25], 0
// 0090b1f4  c21400               ret 0x14
// standard library map_int<pod20> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;

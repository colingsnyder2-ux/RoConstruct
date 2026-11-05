// from server: 100% by auto
// roc 2011-06 007a6de0  unit: RBX::PrismPoly  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a6de0
//
// 007a6de0  6a28                 push 0x28
// 007a6de2  e877320600           call 0x80a05e
// 007a6de7  83c404               add esp, 4
// 007a6dea  85c0                 test eax, eax
// 007a6dec  7446                 je 0x7a6e34
// 007a6dee  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007a6df2  8b542408             mov edx, dword ptr [esp + 8]
// 007a6df6  8908                 mov dword ptr [eax], ecx
// 007a6df8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007a6dfc  894808               mov dword ptr [eax + 8], ecx
// 007a6dff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a6e03  895004               mov dword ptr [eax + 4], edx
// 007a6e06  8b11                 mov edx, dword ptr [ecx]
// 007a6e08  89500c               mov dword ptr [eax + 0xc], edx
// 007a6e0b  8b5104               mov edx, dword ptr [ecx + 4]
// 007a6e0e  895010               mov dword ptr [eax + 0x10], edx
// 007a6e11  8b5108               mov edx, dword ptr [ecx + 8]
// 007a6e14  895014               mov dword ptr [eax + 0x14], edx
// 007a6e17  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007a6e1a  895018               mov dword ptr [eax + 0x18], edx
// 007a6e1d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007a6e20  89501c               mov dword ptr [eax + 0x1c], edx
// 007a6e23  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 007a6e26  8a542414             mov dl, byte ptr [esp + 0x14]
// 007a6e2a  894820               mov dword ptr [eax + 0x20], ecx
// 007a6e2d  885024               mov byte ptr [eax + 0x24], dl
// 007a6e30  c6402500             mov byte ptr [eax + 0x25], 0
// 007a6e34  c21400               ret 0x14
// standard library map_int<pod20> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;

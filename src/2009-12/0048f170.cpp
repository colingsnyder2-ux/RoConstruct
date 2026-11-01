// from server: 100% by auto
// roc 2009-12 0048f170  unit: RBX::RbxTextureProxy  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f170
//
// 0048f170  6a24                 push 0x24
// 0048f172  e8e9463600           call 0x7f3860
// 0048f177  83c404               add esp, 4
// 0048f17a  85c0                 test eax, eax
// 0048f17c  7440                 je 0x48f1be
// 0048f17e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0048f182  8b542408             mov edx, dword ptr [esp + 8]
// 0048f186  8908                 mov dword ptr [eax], ecx
// 0048f188  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048f18c  894808               mov dword ptr [eax + 8], ecx
// 0048f18f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048f193  895004               mov dword ptr [eax + 4], edx
// 0048f196  8b11                 mov edx, dword ptr [ecx]
// 0048f198  89500c               mov dword ptr [eax + 0xc], edx
// 0048f19b  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f19e  895010               mov dword ptr [eax + 0x10], edx
// 0048f1a1  8b5108               mov edx, dword ptr [ecx + 8]
// 0048f1a4  895014               mov dword ptr [eax + 0x14], edx
// 0048f1a7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0048f1aa  895018               mov dword ptr [eax + 0x18], edx
// 0048f1ad  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0048f1b0  8a542414             mov dl, byte ptr [esp + 0x14]
// 0048f1b4  89481c               mov dword ptr [eax + 0x1c], ecx
// 0048f1b7  885020               mov byte ptr [eax + 0x20], dl
// 0048f1ba  c6402100             mov byte ptr [eax + 0x21], 0
// 0048f1be  c21400               ret 0x14
// standard library map_int<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;

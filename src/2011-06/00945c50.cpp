// from server: 100% by auto
// roc 2011-06 00945c50  unit: RBX::RbxTextureProxy  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00945c50
//
// 00945c50  6a24                 push 0x24
// 00945c52  e80744ecff           call 0x80a05e
// 00945c57  83c404               add esp, 4
// 00945c5a  85c0                 test eax, eax
// 00945c5c  7440                 je 0x945c9e
// 00945c5e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00945c62  8b542408             mov edx, dword ptr [esp + 8]
// 00945c66  8908                 mov dword ptr [eax], ecx
// 00945c68  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00945c6c  894808               mov dword ptr [eax + 8], ecx
// 00945c6f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00945c73  895004               mov dword ptr [eax + 4], edx
// 00945c76  8b11                 mov edx, dword ptr [ecx]
// 00945c78  89500c               mov dword ptr [eax + 0xc], edx
// 00945c7b  8b5104               mov edx, dword ptr [ecx + 4]
// 00945c7e  895010               mov dword ptr [eax + 0x10], edx
// 00945c81  8b5108               mov edx, dword ptr [ecx + 8]
// 00945c84  895014               mov dword ptr [eax + 0x14], edx
// 00945c87  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00945c8a  895018               mov dword ptr [eax + 0x18], edx
// 00945c8d  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00945c90  8a542414             mov dl, byte ptr [esp + 0x14]
// 00945c94  89481c               mov dword ptr [eax + 0x1c], ecx
// 00945c97  885020               mov byte ptr [eax + 0x20], dl
// 00945c9a  c6402100             mov byte ptr [eax + 0x21], 0
// 00945c9e  c21400               ret 0x14
// standard library map_int<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2012-06 004ea4f0  unit: RBX::RbxTextureProxy  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ea4f0
//
// 004ea4f0  6a24                 push 0x24
// 004ea4f2  e8237c4900           call 0x98211a
// 004ea4f7  83c404               add esp, 4
// 004ea4fa  85c0                 test eax, eax
// 004ea4fc  7440                 je 0x4ea53e
// 004ea4fe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004ea502  8b542408             mov edx, dword ptr [esp + 8]
// 004ea506  8908                 mov dword ptr [eax], ecx
// 004ea508  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ea50c  894808               mov dword ptr [eax + 8], ecx
// 004ea50f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ea513  895004               mov dword ptr [eax + 4], edx
// 004ea516  8b11                 mov edx, dword ptr [ecx]
// 004ea518  89500c               mov dword ptr [eax + 0xc], edx
// 004ea51b  8b5104               mov edx, dword ptr [ecx + 4]
// 004ea51e  895010               mov dword ptr [eax + 0x10], edx
// 004ea521  8b5108               mov edx, dword ptr [ecx + 8]
// 004ea524  895014               mov dword ptr [eax + 0x14], edx
// 004ea527  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004ea52a  895018               mov dword ptr [eax + 0x18], edx
// 004ea52d  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004ea530  8a542414             mov dl, byte ptr [esp + 0x14]
// 004ea534  89481c               mov dword ptr [eax + 0x1c], ecx
// 004ea537  885020               mov byte ptr [eax + 0x20], dl
// 004ea53a  c6402100             mov byte ptr [eax + 0x21], 0
// 004ea53e  c21400               ret 0x14
// standard library map_int<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;

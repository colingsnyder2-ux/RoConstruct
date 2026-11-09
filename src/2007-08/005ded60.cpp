// from server: 100% by auto
// roc 2007-08 005ded60  unit: RBX::VMotorFeature::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ded60
//
// 005ded60  6a1c                 push 0x1c
// 005ded62  e88f110500           call 0x62fef6
// 005ded67  83c404               add esp, 4
// 005ded6a  85c0                 test eax, eax
// 005ded6c  7434                 je 0x5deda2
// 005ded6e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005ded72  8b542408             mov edx, dword ptr [esp + 8]
// 005ded76  8908                 mov dword ptr [eax], ecx
// 005ded78  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ded7c  894808               mov dword ptr [eax + 8], ecx
// 005ded7f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ded83  895004               mov dword ptr [eax + 4], edx
// 005ded86  8b11                 mov edx, dword ptr [ecx]
// 005ded88  89500c               mov dword ptr [eax + 0xc], edx
// 005ded8b  8b5104               mov edx, dword ptr [ecx + 4]
// 005ded8e  895010               mov dword ptr [eax + 0x10], edx
// 005ded91  8b4908               mov ecx, dword ptr [ecx + 8]
// 005ded94  8a542414             mov dl, byte ptr [esp + 0x14]
// 005ded98  894814               mov dword ptr [eax + 0x14], ecx
// 005ded9b  885018               mov byte ptr [eax + 0x18], dl
// 005ded9e  c6401900             mov byte ptr [eax + 0x19], 0
// 005deda2  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

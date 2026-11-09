// from server: 100% by auto
// roc 2009-06 00698df0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00698df0
//
// 00698df0  6a18                 push 0x18
// 00698df2  e841fc0700           call 0x718a38
// 00698df7  83c404               add esp, 4
// 00698dfa  85c0                 test eax, eax
// 00698dfc  742e                 je 0x698e2c
// 00698dfe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00698e02  8b542408             mov edx, dword ptr [esp + 8]
// 00698e06  8908                 mov dword ptr [eax], ecx
// 00698e08  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00698e0c  894808               mov dword ptr [eax + 8], ecx
// 00698e0f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00698e13  895004               mov dword ptr [eax + 4], edx
// 00698e16  8b11                 mov edx, dword ptr [ecx]
// 00698e18  89500c               mov dword ptr [eax + 0xc], edx
// 00698e1b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00698e1e  8a542414             mov dl, byte ptr [esp + 0x14]
// 00698e22  894810               mov dword ptr [eax + 0x10], ecx
// 00698e25  885014               mov byte ptr [eax + 0x14], dl
// 00698e28  c6401500             mov byte ptr [eax + 0x15], 0
// 00698e2c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

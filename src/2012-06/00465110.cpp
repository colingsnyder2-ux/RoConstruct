// from server: 100% by auto
// roc 2012-06 00465110  unit: VCRenderSettingsItem::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00465110
//
// 00465110  6a18                 push 0x18
// 00465112  e803d05100           call 0x98211a
// 00465117  83c404               add esp, 4
// 0046511a  85c0                 test eax, eax
// 0046511c  742e                 je 0x46514c
// 0046511e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00465122  8b542408             mov edx, dword ptr [esp + 8]
// 00465126  8908                 mov dword ptr [eax], ecx
// 00465128  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046512c  894808               mov dword ptr [eax + 8], ecx
// 0046512f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00465133  895004               mov dword ptr [eax + 4], edx
// 00465136  8b11                 mov edx, dword ptr [ecx]
// 00465138  89500c               mov dword ptr [eax + 0xc], edx
// 0046513b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046513e  8a542414             mov dl, byte ptr [esp + 0x14]
// 00465142  894810               mov dword ptr [eax + 0x10], ecx
// 00465145  885014               mov byte ptr [eax + 0x14], dl
// 00465148  c6401500             mov byte ptr [eax + 0x15], 0
// 0046514c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

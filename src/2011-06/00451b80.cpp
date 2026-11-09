// from server: 100% by auto
// roc 2011-06 00451b80  unit: VCRenderSettingsItem::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00451b80
//
// 00451b80  6a18                 push 0x18
// 00451b82  e8d7843b00           call 0x80a05e
// 00451b87  83c404               add esp, 4
// 00451b8a  85c0                 test eax, eax
// 00451b8c  742e                 je 0x451bbc
// 00451b8e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00451b92  8b542408             mov edx, dword ptr [esp + 8]
// 00451b96  8908                 mov dword ptr [eax], ecx
// 00451b98  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00451b9c  894808               mov dword ptr [eax + 8], ecx
// 00451b9f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00451ba3  895004               mov dword ptr [eax + 4], edx
// 00451ba6  8b11                 mov edx, dword ptr [ecx]
// 00451ba8  89500c               mov dword ptr [eax + 0xc], edx
// 00451bab  8b4904               mov ecx, dword ptr [ecx + 4]
// 00451bae  8a542414             mov dl, byte ptr [esp + 0x14]
// 00451bb2  894810               mov dword ptr [eax + 0x10], ecx
// 00451bb5  885014               mov byte ptr [eax + 0x14], dl
// 00451bb8  c6401500             mov byte ptr [eax + 0x15], 0
// 00451bbc  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

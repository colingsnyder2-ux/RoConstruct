// from server: 100% by auto
// roc 2010-06 005c8d50  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005c8d50
//
// 005c8d50  6a18                 push 0x18
// 005c8d52  e849ec1d00           call 0x7a79a0
// 005c8d57  83c404               add esp, 4
// 005c8d5a  85c0                 test eax, eax
// 005c8d5c  742e                 je 0x5c8d8c
// 005c8d5e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c8d62  8b542408             mov edx, dword ptr [esp + 8]
// 005c8d66  8908                 mov dword ptr [eax], ecx
// 005c8d68  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c8d6c  894808               mov dword ptr [eax + 8], ecx
// 005c8d6f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c8d73  895004               mov dword ptr [eax + 4], edx
// 005c8d76  8b11                 mov edx, dword ptr [ecx]
// 005c8d78  89500c               mov dword ptr [eax + 0xc], edx
// 005c8d7b  8b4904               mov ecx, dword ptr [ecx + 4]
// 005c8d7e  8a542414             mov dl, byte ptr [esp + 0x14]
// 005c8d82  894810               mov dword ptr [eax + 0x10], ecx
// 005c8d85  885014               mov byte ptr [eax + 0x14], dl
// 005c8d88  c6401500             mov byte ptr [eax + 0x15], 0
// 005c8d8c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

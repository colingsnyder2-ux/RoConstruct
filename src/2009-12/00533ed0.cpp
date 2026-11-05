// from server: 100% by auto
// roc 2009-12 00533ed0  unit: RBX::Network::IdSerializer  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00533ed0
//
// 00533ed0  6a18                 push 0x18
// 00533ed2  e889f92b00           call 0x7f3860
// 00533ed7  83c404               add esp, 4
// 00533eda  85c0                 test eax, eax
// 00533edc  742e                 je 0x533f0c
// 00533ede  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00533ee2  8b542408             mov edx, dword ptr [esp + 8]
// 00533ee6  8908                 mov dword ptr [eax], ecx
// 00533ee8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00533eec  894808               mov dword ptr [eax + 8], ecx
// 00533eef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00533ef3  895004               mov dword ptr [eax + 4], edx
// 00533ef6  8b11                 mov edx, dword ptr [ecx]
// 00533ef8  89500c               mov dword ptr [eax + 0xc], edx
// 00533efb  8b4904               mov ecx, dword ptr [ecx + 4]
// 00533efe  8a542414             mov dl, byte ptr [esp + 0x14]
// 00533f02  894810               mov dword ptr [eax + 0x10], ecx
// 00533f05  885014               mov byte ptr [eax + 0x14], dl
// 00533f08  c6401500             mov byte ptr [eax + 0x15], 0
// 00533f0c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

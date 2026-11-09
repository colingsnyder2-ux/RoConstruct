// from server: 100% by auto
// roc 2007-08 005dab30  unit: RBX::VHole::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dab30
//
// 005dab30  6a18                 push 0x18
// 005dab32  e8bf530500           call 0x62fef6
// 005dab37  83c404               add esp, 4
// 005dab3a  85c0                 test eax, eax
// 005dab3c  742e                 je 0x5dab6c
// 005dab3e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005dab42  8b542408             mov edx, dword ptr [esp + 8]
// 005dab46  8908                 mov dword ptr [eax], ecx
// 005dab48  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005dab4c  894808               mov dword ptr [eax + 8], ecx
// 005dab4f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dab53  895004               mov dword ptr [eax + 4], edx
// 005dab56  8b11                 mov edx, dword ptr [ecx]
// 005dab58  89500c               mov dword ptr [eax + 0xc], edx
// 005dab5b  8b4904               mov ecx, dword ptr [ecx + 4]
// 005dab5e  8a542414             mov dl, byte ptr [esp + 0x14]
// 005dab62  894810               mov dword ptr [eax + 0x10], ecx
// 005dab65  885014               mov byte ptr [eax + 0x14], dl
// 005dab68  c6401500             mov byte ptr [eax + 0x15], 0
// 005dab6c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

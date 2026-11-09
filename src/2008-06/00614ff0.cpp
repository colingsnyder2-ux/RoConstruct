// from server: 100% by auto
// roc 2008-06 00614ff0  unit: RBX::RevoluteLink  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00614ff0
//
// 00614ff0  6a18                 push 0x18
// 00614ff2  e829b90800           call 0x6a0920
// 00614ff7  83c404               add esp, 4
// 00614ffa  85c0                 test eax, eax
// 00614ffc  742e                 je 0x61502c
// 00614ffe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00615002  8b542408             mov edx, dword ptr [esp + 8]
// 00615006  8908                 mov dword ptr [eax], ecx
// 00615008  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061500c  894808               mov dword ptr [eax + 8], ecx
// 0061500f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00615013  895004               mov dword ptr [eax + 4], edx
// 00615016  8b11                 mov edx, dword ptr [ecx]
// 00615018  89500c               mov dword ptr [eax + 0xc], edx
// 0061501b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061501e  8a542414             mov dl, byte ptr [esp + 0x14]
// 00615022  894810               mov dword ptr [eax + 0x10], ecx
// 00615025  885014               mov byte ptr [eax + 0x14], dl
// 00615028  c6401500             mov byte ptr [eax + 0x15], 0
// 0061502c  c21400               ret 0x14
// standard library map_int<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHPAUT@@@2@D@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;

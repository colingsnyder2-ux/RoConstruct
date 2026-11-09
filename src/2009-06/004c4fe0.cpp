// from server: 100% by auto
// roc 2009-06 004c4fe0  unit: RBX::Network::Players::Plugin  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4fe0
//
// 004c4fe0  6a1c                 push 0x1c
// 004c4fe2  e8513a2500           call 0x718a38
// 004c4fe7  83c404               add esp, 4
// 004c4fea  85c0                 test eax, eax
// 004c4fec  7434                 je 0x4c5022
// 004c4fee  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c4ff2  8b542408             mov edx, dword ptr [esp + 8]
// 004c4ff6  8908                 mov dword ptr [eax], ecx
// 004c4ff8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c4ffc  894808               mov dword ptr [eax + 8], ecx
// 004c4fff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c5003  895004               mov dword ptr [eax + 4], edx
// 004c5006  8b11                 mov edx, dword ptr [ecx]
// 004c5008  89500c               mov dword ptr [eax + 0xc], edx
// 004c500b  8b5104               mov edx, dword ptr [ecx + 4]
// 004c500e  895010               mov dword ptr [eax + 0x10], edx
// 004c5011  8b4908               mov ecx, dword ptr [ecx + 8]
// 004c5014  8a542414             mov dl, byte ptr [esp + 0x14]
// 004c5018  894814               mov dword ptr [eax + 0x14], ecx
// 004c501b  885018               mov byte ptr [eax + 0x18], dl
// 004c501e  c6401900             mov byte ptr [eax + 0x19], 0
// 004c5022  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

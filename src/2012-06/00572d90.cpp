// from server: 100% by auto
// roc 2012-06 00572d90  unit: AsyncResult  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00572d90
//
// 00572d90  6a1c                 push 0x1c
// 00572d92  e883f34000           call 0x98211a
// 00572d97  83c404               add esp, 4
// 00572d9a  85c0                 test eax, eax
// 00572d9c  7434                 je 0x572dd2
// 00572d9e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00572da2  8b542408             mov edx, dword ptr [esp + 8]
// 00572da6  8908                 mov dword ptr [eax], ecx
// 00572da8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00572dac  894808               mov dword ptr [eax + 8], ecx
// 00572daf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00572db3  895004               mov dword ptr [eax + 4], edx
// 00572db6  8b11                 mov edx, dword ptr [ecx]
// 00572db8  89500c               mov dword ptr [eax + 0xc], edx
// 00572dbb  8b5104               mov edx, dword ptr [ecx + 4]
// 00572dbe  895010               mov dword ptr [eax + 0x10], edx
// 00572dc1  8b4908               mov ecx, dword ptr [ecx + 8]
// 00572dc4  8a542414             mov dl, byte ptr [esp + 0x14]
// 00572dc8  894814               mov dword ptr [eax + 0x14], ecx
// 00572dcb  885018               mov byte ptr [eax + 0x18], dl
// 00572dce  c6401900             mov byte ptr [eax + 0x19], 0
// 00572dd2  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

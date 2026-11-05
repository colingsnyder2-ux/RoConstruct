// from server: 100% by auto
// roc 2010-06 004c1750  unit: RBX::Network::Players::W4ChatOption::?$holder  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c1750
//
// 004c1750  6a1c                 push 0x1c
// 004c1752  e849622e00           call 0x7a79a0
// 004c1757  83c404               add esp, 4
// 004c175a  85c0                 test eax, eax
// 004c175c  7434                 je 0x4c1792
// 004c175e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c1762  8b542408             mov edx, dword ptr [esp + 8]
// 004c1766  8908                 mov dword ptr [eax], ecx
// 004c1768  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c176c  894808               mov dword ptr [eax + 8], ecx
// 004c176f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c1773  895004               mov dword ptr [eax + 4], edx
// 004c1776  8b11                 mov edx, dword ptr [ecx]
// 004c1778  89500c               mov dword ptr [eax + 0xc], edx
// 004c177b  8b5104               mov edx, dword ptr [ecx + 4]
// 004c177e  895010               mov dword ptr [eax + 0x10], edx
// 004c1781  8b4908               mov ecx, dword ptr [ecx + 8]
// 004c1784  8a542414             mov dl, byte ptr [esp + 0x14]
// 004c1788  894814               mov dword ptr [eax + 0x14], ecx
// 004c178b  885018               mov byte ptr [eax + 0x18], dl
// 004c178e  c6401900             mov byte ptr [eax + 0x19], 0
// 004c1792  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

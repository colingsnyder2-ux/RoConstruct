// from server: 100% by auto
// roc 2011-06 004f6600  unit: RBX::VRbxRay::?$holder  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f6600
//
// 004f6600  6a1c                 push 0x1c
// 004f6602  e8573a3100           call 0x80a05e
// 004f6607  83c404               add esp, 4
// 004f660a  85c0                 test eax, eax
// 004f660c  7434                 je 0x4f6642
// 004f660e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004f6612  8b542408             mov edx, dword ptr [esp + 8]
// 004f6616  8908                 mov dword ptr [eax], ecx
// 004f6618  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004f661c  894808               mov dword ptr [eax + 8], ecx
// 004f661f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f6623  895004               mov dword ptr [eax + 4], edx
// 004f6626  8b11                 mov edx, dword ptr [ecx]
// 004f6628  89500c               mov dword ptr [eax + 0xc], edx
// 004f662b  8b5104               mov edx, dword ptr [ecx + 4]
// 004f662e  895010               mov dword ptr [eax + 0x10], edx
// 004f6631  8b4908               mov ecx, dword ptr [ecx + 8]
// 004f6634  8a542414             mov dl, byte ptr [esp + 0x14]
// 004f6638  894814               mov dword ptr [eax + 0x14], ecx
// 004f663b  885018               mov byte ptr [eax + 0x18], dl
// 004f663e  c6401900             mov byte ptr [eax + 0x19], 0
// 004f6642  c21400               ret 0x14
// standard library map_int<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;

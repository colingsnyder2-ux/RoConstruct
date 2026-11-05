// from server: 100% by auto
// roc 2011-06 0078a8b0  unit: RBX::Block  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078a8b0
//
// 0078a8b0  6a20                 push 0x20
// 0078a8b2  e8a7f70700           call 0x80a05e
// 0078a8b7  83c404               add esp, 4
// 0078a8ba  85c0                 test eax, eax
// 0078a8bc  743a                 je 0x78a8f8
// 0078a8be  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078a8c2  8b542408             mov edx, dword ptr [esp + 8]
// 0078a8c6  8908                 mov dword ptr [eax], ecx
// 0078a8c8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0078a8cc  894808               mov dword ptr [eax + 8], ecx
// 0078a8cf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0078a8d3  895004               mov dword ptr [eax + 4], edx
// 0078a8d6  8b11                 mov edx, dword ptr [ecx]
// 0078a8d8  89500c               mov dword ptr [eax + 0xc], edx
// 0078a8db  8b5104               mov edx, dword ptr [ecx + 4]
// 0078a8de  895010               mov dword ptr [eax + 0x10], edx
// 0078a8e1  8b5108               mov edx, dword ptr [ecx + 8]
// 0078a8e4  895014               mov dword ptr [eax + 0x14], edx
// 0078a8e7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0078a8ea  8a542414             mov dl, byte ptr [esp + 0x14]
// 0078a8ee  894818               mov dword ptr [eax + 0x18], ecx
// 0078a8f1  88501c               mov byte ptr [eax + 0x1c], dl
// 0078a8f4  c6401d00             mov byte ptr [eax + 0x1d], 0
// 0078a8f8  c21400               ret 0x14
// standard library map_int<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;

// from server: 100% by auto
// roc 2010-06 008e3330  unit: RBX::RbxTextureProxy  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3330
//
// 008e3330  6a24                 push 0x24
// 008e3332  e86946ecff           call 0x7a79a0
// 008e3337  83c404               add esp, 4
// 008e333a  85c0                 test eax, eax
// 008e333c  7440                 je 0x8e337e
// 008e333e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e3342  8b542408             mov edx, dword ptr [esp + 8]
// 008e3346  8908                 mov dword ptr [eax], ecx
// 008e3348  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e334c  894808               mov dword ptr [eax + 8], ecx
// 008e334f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e3353  895004               mov dword ptr [eax + 4], edx
// 008e3356  8b11                 mov edx, dword ptr [ecx]
// 008e3358  89500c               mov dword ptr [eax + 0xc], edx
// 008e335b  8b5104               mov edx, dword ptr [ecx + 4]
// 008e335e  895010               mov dword ptr [eax + 0x10], edx
// 008e3361  8b5108               mov edx, dword ptr [ecx + 8]
// 008e3364  895014               mov dword ptr [eax + 0x14], edx
// 008e3367  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008e336a  895018               mov dword ptr [eax + 0x18], edx
// 008e336d  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008e3370  8a542414             mov dl, byte ptr [esp + 0x14]
// 008e3374  89481c               mov dword ptr [eax + 0x1c], ecx
// 008e3377  885020               mov byte ptr [eax + 0x20], dl
// 008e337a  c6402100             mov byte ptr [eax + 0x21], 0
// 008e337e  c21400               ret 0x14
// standard library map_int<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHUE@@@2@D@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;

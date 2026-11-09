// from server: 100% by auto
// roc 2009-06 004fbc30  unit: RBX::Network::ServerReplicator  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fbc30
//
// 004fbc30  6a3c                 push 0x3c
// 004fbc32  e801ce2100           call 0x718a38
// 004fbc37  83c404               add esp, 4
// 004fbc3a  85c0                 test eax, eax
// 004fbc3c  7406                 je 0x4fbc44
// 004fbc3e  c70000000000         mov dword ptr [eax], 0
// 004fbc44  8d4804               lea ecx, [eax + 4]
// 004fbc47  85c9                 test ecx, ecx
// 004fbc49  7406                 je 0x4fbc51
// 004fbc4b  c70100000000         mov dword ptr [ecx], 0
// 004fbc51  8d4808               lea ecx, [eax + 8]
// 004fbc54  85c9                 test ecx, ecx
// 004fbc56  7406                 je 0x4fbc5e
// 004fbc58  c70100000000         mov dword ptr [ecx], 0
// 004fbc5e  c6403801             mov byte ptr [eax + 0x38], 1
// 004fbc62  c6403900             mov byte ptr [eax + 0x39], 0
// 004fbc66  c3                   ret 
// standard library map_int<pod40> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@XZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;

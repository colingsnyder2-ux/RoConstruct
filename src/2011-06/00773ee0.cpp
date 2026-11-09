// from server: 100% by auto
// roc 2011-06 00773ee0  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00773ee0
//
// 00773ee0  6a34                 push 0x34
// 00773ee2  e877610900           call 0x80a05e
// 00773ee7  83c404               add esp, 4
// 00773eea  85c0                 test eax, eax
// 00773eec  7406                 je 0x773ef4
// 00773eee  c70000000000         mov dword ptr [eax], 0
// 00773ef4  8d4804               lea ecx, [eax + 4]
// 00773ef7  85c9                 test ecx, ecx
// 00773ef9  7406                 je 0x773f01
// 00773efb  c70100000000         mov dword ptr [ecx], 0
// 00773f01  8d4808               lea ecx, [eax + 8]
// 00773f04  85c9                 test ecx, ecx
// 00773f06  7406                 je 0x773f0e
// 00773f08  c70100000000         mov dword ptr [ecx], 0
// 00773f0e  c6403001             mov byte ptr [eax + 0x30], 1
// 00773f12  c6403100             mov byte ptr [eax + 0x31], 0
// 00773f16  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2012-06 00846360  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00846360
//
// 00846360  6a38                 push 0x38
// 00846362  e8b3bd1300           call 0x98211a
// 00846367  83c404               add esp, 4
// 0084636a  85c0                 test eax, eax
// 0084636c  7406                 je 0x846374
// 0084636e  c70000000000         mov dword ptr [eax], 0
// 00846374  8d4804               lea ecx, [eax + 4]
// 00846377  85c9                 test ecx, ecx
// 00846379  7406                 je 0x846381
// 0084637b  c70100000000         mov dword ptr [ecx], 0
// 00846381  8d4808               lea ecx, [eax + 8]
// 00846384  85c9                 test ecx, ecx
// 00846386  7406                 je 0x84638e
// 00846388  c70100000000         mov dword ptr [ecx], 0
// 0084638e  c6403401             mov byte ptr [eax + 0x34], 1
// 00846392  c6403500             mov byte ptr [eax + 0x35], 0
// 00846396  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

// from server: 100% by auto
// roc 2009-06 0043ffa0  unit: VCRenderSettingsItem::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ffa0
//
// 0043ffa0  6a18                 push 0x18
// 0043ffa2  e8918a2d00           call 0x718a38
// 0043ffa7  83c404               add esp, 4
// 0043ffaa  85c0                 test eax, eax
// 0043ffac  7406                 je 0x43ffb4
// 0043ffae  c70000000000         mov dword ptr [eax], 0
// 0043ffb4  8d4804               lea ecx, [eax + 4]
// 0043ffb7  85c9                 test ecx, ecx
// 0043ffb9  7406                 je 0x43ffc1
// 0043ffbb  c70100000000         mov dword ptr [ecx], 0
// 0043ffc1  8d4808               lea ecx, [eax + 8]
// 0043ffc4  85c9                 test ecx, ecx
// 0043ffc6  7406                 je 0x43ffce
// 0043ffc8  c70100000000         mov dword ptr [ecx], 0
// 0043ffce  c6401401             mov byte ptr [eax + 0x14], 1
// 0043ffd2  c6401500             mov byte ptr [eax + 0x15], 0
// 0043ffd6  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

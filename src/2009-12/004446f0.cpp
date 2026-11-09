// from server: 100% by auto
// roc 2009-12 004446f0  unit: VCRenderSettingsItem::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004446f0
//
// 004446f0  6a18                 push 0x18
// 004446f2  e869f13a00           call 0x7f3860
// 004446f7  83c404               add esp, 4
// 004446fa  85c0                 test eax, eax
// 004446fc  7406                 je 0x444704
// 004446fe  c70000000000         mov dword ptr [eax], 0
// 00444704  8d4804               lea ecx, [eax + 4]
// 00444707  85c9                 test ecx, ecx
// 00444709  7406                 je 0x444711
// 0044470b  c70100000000         mov dword ptr [ecx], 0
// 00444711  8d4808               lea ecx, [eax + 8]
// 00444714  85c9                 test ecx, ecx
// 00444716  7406                 je 0x44471e
// 00444718  c70100000000         mov dword ptr [ecx], 0
// 0044471e  c6401401             mov byte ptr [eax + 0x14], 1
// 00444722  c6401500             mov byte ptr [eax + 0x15], 0
// 00444726  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;

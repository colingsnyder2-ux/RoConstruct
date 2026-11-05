// from server: 100% by auto
// roc 2011-06 00773c30  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00773c30
//
// 00773c30  6a24                 push 0x24
// 00773c32  e827640900           call 0x80a05e
// 00773c37  83c404               add esp, 4
// 00773c3a  85c0                 test eax, eax
// 00773c3c  7402                 je 0x773c40
// 00773c3e  8900                 mov dword ptr [eax], eax
// 00773c40  8d4804               lea ecx, [eax + 4]
// 00773c43  85c9                 test ecx, ecx
// 00773c45  7402                 je 0x773c49
// 00773c47  8901                 mov dword ptr [ecx], eax
// 00773c49  c3                   ret 
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;

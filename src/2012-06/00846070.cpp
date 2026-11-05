// from server: 100% by auto
// roc 2012-06 00846070  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00846070
//
// 00846070  6a24                 push 0x24
// 00846072  e8a3c01300           call 0x98211a
// 00846077  83c404               add esp, 4
// 0084607a  85c0                 test eax, eax
// 0084607c  7402                 je 0x846080
// 0084607e  8900                 mov dword ptr [eax], eax
// 00846080  8d4804               lea ecx, [eax + 4]
// 00846083  85c9                 test ecx, ecx
// 00846085  7402                 je 0x846089
// 00846087  8901                 mov dword ptr [ecx], eax
// 00846089  c3                   ret 
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;

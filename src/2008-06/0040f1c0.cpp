// from server: 100% by auto
// roc 2008-06 0040f1c0  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f1c0
//
// 0040f1c0  6a24                 push 0x24
// 0040f1c2  e859172900           call 0x6a0920
// 0040f1c7  83c404               add esp, 4
// 0040f1ca  85c0                 test eax, eax
// 0040f1cc  7402                 je 0x40f1d0
// 0040f1ce  8900                 mov dword ptr [eax], eax
// 0040f1d0  8d4804               lea ecx, [eax + 4]
// 0040f1d3  85c9                 test ecx, ecx
// 0040f1d5  7402                 je 0x40f1d9
// 0040f1d7  8901                 mov dword ptr [ecx], eax
// 0040f1d9  c3                   ret 
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;

// from server: 100% by auto
// roc 2007-08 004287d0  unit: COleException  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004287d0
//
// 004287d0  56                   push esi
// 004287d1  8b742408             mov esi, dword ptr [esp + 8]
// 004287d5  57                   push edi
// 004287d6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004287da  3bf7                 cmp esi, edi
// 004287dc  7416                 je 0x4287f4
// 004287de  53                   push ebx
// 004287df  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004287e3  53                   push ebx
// 004287e4  8bce                 mov ecx, esi
// 004287e6  ff1590e67700         call dword ptr [0x77e690]
// 004287ec  83c61c               add esi, 0x1c
// 004287ef  3bf7                 cmp esi, edi
// 004287f1  75f0                 jne 0x4287e3
// 004287f3  5b                   pop ebx
// 004287f4  5f                   pop edi
// 004287f5  5e                   pop esi
// 004287f6  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

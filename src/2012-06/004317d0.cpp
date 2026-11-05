// from server: 100% by auto
// roc 2012-06 004317d0  unit: LogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004317d0
//
// 004317d0  56                   push esi
// 004317d1  8b742408             mov esi, dword ptr [esp + 8]
// 004317d5  57                   push edi
// 004317d6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004317da  3bf7                 cmp esi, edi
// 004317dc  7416                 je 0x4317f4
// 004317de  53                   push ebx
// 004317df  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004317e3  53                   push ebx
// 004317e4  8bce                 mov ecx, esi
// 004317e6  ff155826b200         call dword ptr [0xb22658]
// 004317ec  83c61c               add esi, 0x1c
// 004317ef  3bf7                 cmp esi, edi
// 004317f1  75f0                 jne 0x4317e3
// 004317f3  5b                   pop ebx
// 004317f4  5f                   pop edi
// 004317f5  5e                   pop esi
// 004317f6  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

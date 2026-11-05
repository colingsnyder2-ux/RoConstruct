// from server: 100% by auto
// roc 2011-06 0042cf60  unit: LogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0042cf60
//
// 0042cf60  56                   push esi
// 0042cf61  8b742408             mov esi, dword ptr [esp + 8]
// 0042cf65  57                   push edi
// 0042cf66  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042cf6a  3bf7                 cmp esi, edi
// 0042cf6c  7416                 je 0x42cf84
// 0042cf6e  53                   push ebx
// 0042cf6f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0042cf73  53                   push ebx
// 0042cf74  8bce                 mov ecx, esi
// 0042cf76  ff15a804a400         call dword ptr [0xa404a8]
// 0042cf7c  83c61c               add esi, 0x1c
// 0042cf7f  3bf7                 cmp esi, edi
// 0042cf81  75f0                 jne 0x42cf73
// 0042cf83  5b                   pop ebx
// 0042cf84  5f                   pop edi
// 0042cf85  5e                   pop esi
// 0042cf86  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

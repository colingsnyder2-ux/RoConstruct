// from server: 100% by auto
// roc 2009-12 00424490  unit: ThreadLogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00424490
//
// 00424490  56                   push esi
// 00424491  8b742408             mov esi, dword ptr [esp + 8]
// 00424495  57                   push edi
// 00424496  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042449a  3bf7                 cmp esi, edi
// 0042449c  7416                 je 0x4244b4
// 0042449e  53                   push ebx
// 0042449f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004244a3  53                   push ebx
// 004244a4  8bce                 mov ecx, esi
// 004244a6  ff159cb69800         call dword ptr [0x98b69c]
// 004244ac  83c61c               add esi, 0x1c
// 004244af  3bf7                 cmp esi, edi
// 004244b1  75f0                 jne 0x4244a3
// 004244b3  5b                   pop ebx
// 004244b4  5f                   pop edi
// 004244b5  5e                   pop esi
// 004244b6  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

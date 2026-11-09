// from server: 100% by auto
// roc 2010-06 00424740  unit: ThreadLogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00424740
//
// 00424740  56                   push esi
// 00424741  8b742408             mov esi, dword ptr [esp + 8]
// 00424745  57                   push edi
// 00424746  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042474a  3bf7                 cmp esi, edi
// 0042474c  7416                 je 0x424764
// 0042474e  53                   push ebx
// 0042474f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00424753  53                   push ebx
// 00424754  8bce                 mov ecx, esi
// 00424756  ff1568a49e00         call dword ptr [0x9ea468]
// 0042475c  83c61c               add esi, 0x1c
// 0042475f  3bf7                 cmp esi, edi
// 00424761  75f0                 jne 0x424753
// 00424763  5b                   pop ebx
// 00424764  5f                   pop edi
// 00424765  5e                   pop esi
// 00424766  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2009-06 00423ae0  unit: MainLogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00423ae0
//
// 00423ae0  56                   push esi
// 00423ae1  8b742408             mov esi, dword ptr [esp + 8]
// 00423ae5  57                   push edi
// 00423ae6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00423aea  3bf7                 cmp esi, edi
// 00423aec  7416                 je 0x423b04
// 00423aee  53                   push ebx
// 00423aef  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00423af3  53                   push ebx
// 00423af4  8bce                 mov ecx, esi
// 00423af6  ff1564e48900         call dword ptr [0x89e464]
// 00423afc  83c61c               add esi, 0x1c
// 00423aff  3bf7                 cmp esi, edi
// 00423b01  75f0                 jne 0x423af3
// 00423b03  5b                   pop ebx
// 00423b04  5f                   pop edi
// 00423b05  5e                   pop esi
// 00423b06  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2008-06 00428990  unit: MainLogManager  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428990
//
// 00428990  56                   push esi
// 00428991  8b742408             mov esi, dword ptr [esp + 8]
// 00428995  57                   push edi
// 00428996  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042899a  3bf7                 cmp esi, edi
// 0042899c  7416                 je 0x4289b4
// 0042899e  53                   push ebx
// 0042899f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004289a3  53                   push ebx
// 004289a4  8bce                 mov ecx, esi
// 004289a6  ff150c248000         call dword ptr [0x80240c]
// 004289ac  83c61c               add esi, 0x1c
// 004289af  3bf7                 cmp esi, edi
// 004289b1  75f0                 jne 0x4289a3
// 004289b3  5b                   pop ebx
// 004289b4  5f                   pop edi
// 004289b5  5e                   pop esi
// 004289b6  c3                   ret 
// standard library vector<string> (function ??$_Fill@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

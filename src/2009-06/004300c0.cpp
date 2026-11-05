// from server: 100% by auto
// roc 2009-06 004300c0  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004300c0
//
// 004300c0  6aff                 push -1
// 004300c2  6878ef8600           push 0x86ef78
// 004300c7  64a100000000         mov eax, dword ptr fs:[0]
// 004300cd  50                   push eax
// 004300ce  64892500000000       mov dword ptr fs:[0], esp
// 004300d5  51                   push ecx
// 004300d6  56                   push esi
// 004300d7  8bf1                 mov esi, ecx
// 004300d9  89742404             mov dword ptr [esp + 4], esi
// 004300dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004300e5  e856fbffff           call 0x42fc40
// 004300ea  8b06                 mov eax, dword ptr [esi]
// 004300ec  50                   push eax
// 004300ed  e840892e00           call 0x718a32
// 004300f2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004300f6  83c404               add esp, 4
// 004300f9  5e                   pop esi
// 004300fa  64890d00000000       mov dword ptr fs:[0], ecx
// 00430101  83c410               add esp, 0x10
// 00430104  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

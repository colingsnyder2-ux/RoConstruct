// from server: 100% by auto
// roc 2008-06 004199e0  unit: VCLuaFunction::?$CComObject  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004199e0
//
// 004199e0  6aff                 push -1
// 004199e2  68e8727d00           push 0x7d72e8
// 004199e7  64a100000000         mov eax, dword ptr fs:[0]
// 004199ed  50                   push eax
// 004199ee  64892500000000       mov dword ptr fs:[0], esp
// 004199f5  51                   push ecx
// 004199f6  56                   push esi
// 004199f7  8bf1                 mov esi, ecx
// 004199f9  89742404             mov dword ptr [esp + 4], esi
// 004199fd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00419a05  e8a6edffff           call 0x4187b0
// 00419a0a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00419a0d  50                   push eax
// 00419a0e  e8676c2800           call 0x6a067a
// 00419a13  8b0e                 mov ecx, dword ptr [esi]
// 00419a15  51                   push ecx
// 00419a16  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00419a1d  e8586c2800           call 0x6a067a
// 00419a22  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00419a26  83c408               add esp, 8
// 00419a29  5e                   pop esi
// 00419a2a  64890d00000000       mov dword ptr fs:[0], ecx
// 00419a31  83c410               add esp, 0x10
// 00419a34  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;

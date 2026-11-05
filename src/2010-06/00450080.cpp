// from server: 100% by auto
// roc 2010-06 00450080  unit: CRobloxModule  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00450080
//
// 00450080  6aff                 push -1
// 00450082  6858a29900           push 0x99a258
// 00450087  64a100000000         mov eax, dword ptr fs:[0]
// 0045008d  50                   push eax
// 0045008e  64892500000000       mov dword ptr fs:[0], esp
// 00450095  51                   push ecx
// 00450096  56                   push esi
// 00450097  8bf1                 mov esi, ecx
// 00450099  89742404             mov dword ptr [esp + 4], esi
// 0045009d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004500a5  e8e6f7ffff           call 0x44f890
// 004500aa  8b06                 mov eax, dword ptr [esi]
// 004500ac  50                   push eax
// 004500ad  e8e8783500           call 0x7a799a
// 004500b2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004500b6  83c404               add esp, 4
// 004500b9  5e                   pop esi
// 004500ba  64890d00000000       mov dword ptr fs:[0], ecx
// 004500c1  83c410               add esp, 0x10
// 004500c4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

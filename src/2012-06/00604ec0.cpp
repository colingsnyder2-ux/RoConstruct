// from server: 100% by auto
// roc 2012-06 00604ec0  unit: seg_00600000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00604ec0
//
// 00604ec0  8b442408             mov eax, dword ptr [esp + 8]
// 00604ec4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00604ec8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00604ecc  2bc1                 sub eax, ecx
// 00604ece  d1f8                 sar eax, 1
// 00604ed0  8d0400               lea eax, [eax + eax]
// 00604ed3  56                   push esi
// 00604ed4  8d3410               lea esi, [eax + edx]
// 00604ed7  740d                 je 0x604ee6
// 00604ed9  50                   push eax
// 00604eda  51                   push ecx
// 00604edb  50                   push eax
// 00604edc  52                   push edx
// 00604edd  ff15c02ab200         call dword ptr [0xb22ac0]
// 00604ee3  83c410               add esp, 0x10
// 00604ee6  8bc6                 mov eax, esi
// 00604ee8  5e                   pop esi
// 00604ee9  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

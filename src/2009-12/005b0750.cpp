// from server: 100% by auto
// roc 2009-12 005b0750  unit: seg_005b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0750
//
// 005b0750  8b442408             mov eax, dword ptr [esp + 8]
// 005b0754  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b0758  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b075c  2bc1                 sub eax, ecx
// 005b075e  d1f8                 sar eax, 1
// 005b0760  8d0400               lea eax, [eax + eax]
// 005b0763  56                   push esi
// 005b0764  8d3410               lea esi, [eax + edx]
// 005b0767  740d                 je 0x5b0776
// 005b0769  50                   push eax
// 005b076a  51                   push ecx
// 005b076b  50                   push eax
// 005b076c  52                   push edx
// 005b076d  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b0773  83c410               add esp, 0x10
// 005b0776  8bc6                 mov eax, esi
// 005b0778  5e                   pop esi
// 005b0779  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

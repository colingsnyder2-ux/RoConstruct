// from server: 100% by auto
// roc 2009-06 0053ada0  unit: RBX::VerticalCylinderBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053ada0
//
// 0053ada0  8b442408             mov eax, dword ptr [esp + 8]
// 0053ada4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0053ada8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0053adac  2bc1                 sub eax, ecx
// 0053adae  d1f8                 sar eax, 1
// 0053adb0  8d0400               lea eax, [eax + eax]
// 0053adb3  56                   push esi
// 0053adb4  8d3410               lea esi, [eax + edx]
// 0053adb7  740d                 je 0x53adc6
// 0053adb9  50                   push eax
// 0053adba  51                   push ecx
// 0053adbb  50                   push eax
// 0053adbc  52                   push edx
// 0053adbd  ff155ce98900         call dword ptr [0x89e95c]
// 0053adc3  83c410               add esp, 0x10
// 0053adc6  8bc6                 mov eax, esi
// 0053adc8  5e                   pop esi
// 0053adc9  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;

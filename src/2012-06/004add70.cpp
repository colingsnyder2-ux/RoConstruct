// from server: 100% by Xemicl
// roc 2012-06 004add70  unit: DxUserInput  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004add70
//
// 004add70  d9ee                 fldz 
// 004add72  8b442410             mov eax, dword ptr [esp + 0x10]
// 004add76  8b542408             mov edx, dword ptr [esp + 8]
// 004add7a  51                   push ecx
// 004add7b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004add7f  d91c24               fstp dword ptr [esp]
// 004add82  6a06                 push 6
// 004add84  50                   push eax
// 004add85  8b442410             mov eax, dword ptr [esp + 0x10]
// 004add89  51                   push ecx
// 004add8a  52                   push edx
// 004add8b  50                   push eax
// 004add8c  e85ffeffff           call 0x4adbf0
// 004add91  83c418               add esp, 0x18
// 004add94  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001d_0046a100@ns_ROCX00001d@@YAXHHHH@Z)

namespace ns_ROCX00001d {
extern void __cdecl helper(int, int, int, int, int, float);

void __cdecl fn_ROCX00001d_0046a100(int a, int b, int c, int d)
{
    helper(a, b, c, d, 6, 0.0f);
}
}

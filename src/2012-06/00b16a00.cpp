// roc 2012-06 00b16a00  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16a00
//
// 00b16a00  b95cf4e200           mov ecx, 0xe2f45c
// 00b16a05  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b16a00 { void m(); };
extern T_func_00b16a00 G1_func_00b16a00;
void func_00b16a00()
{
    G1_func_00b16a00.m();
}

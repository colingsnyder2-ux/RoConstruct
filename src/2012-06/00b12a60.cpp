// roc 2012-06 00b12a60  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12a60
//
// 00b12a60  b9d8c2e100           mov ecx, 0xe1c2d8
// 00b12a65  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12a60 { void m(); };
extern T_func_00b12a60 G1_func_00b12a60;
void func_00b12a60()
{
    G1_func_00b12a60.m();
}

// roc 2012-06 00b18360  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18360
//
// 00b18360  b9045ae300           mov ecx, 0xe35a04
// 00b18365  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b18360 { void m(); };
extern T_func_00b18360 G1_func_00b18360;
void func_00b18360()
{
    G1_func_00b18360.m();
}

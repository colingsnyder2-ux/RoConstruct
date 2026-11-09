// roc 2012-06 00b176a0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b176a0
//
// 00b176a0  b92c20e300           mov ecx, 0xe3202c
// 00b176a5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b176a0 { void m(); };
extern T_func_00b176a0 G1_func_00b176a0;
void func_00b176a0()
{
    G1_func_00b176a0.m();
}

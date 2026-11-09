// roc 2012-06 00b18c50  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c50
//
// 00b18c50  b9dc75e300           mov ecx, 0xe375dc
// 00b18c55  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b18c50 { void m(); };
extern T_func_00b18c50 G1_func_00b18c50;
void func_00b18c50()
{
    G1_func_00b18c50.m();
}

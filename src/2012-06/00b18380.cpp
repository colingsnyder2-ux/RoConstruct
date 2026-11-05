// roc 2012-06 00b18380  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18380
//
// 00b18380  b9485ae300           mov ecx, 0xe35a48
// 00b18385  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b18380 { void m(); };
extern T_func_00b18380 G1_func_00b18380;
void func_00b18380()
{
    G1_func_00b18380.m();
}

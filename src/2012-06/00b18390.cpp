// roc 2012-06 00b18390  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18390
//
// 00b18390  b95859e300           mov ecx, 0xe35958
// 00b18395  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b18390 { void m(); };
extern T_func_00b18390 G1_func_00b18390;
void func_00b18390()
{
    G1_func_00b18390.m();
}

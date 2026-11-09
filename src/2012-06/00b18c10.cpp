// roc 2012-06 00b18c10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c10
//
// 00b18c10  b9b870e300           mov ecx, 0xe370b8
// 00b18c15  e91691c4ff           jmp 0x761d30
// auto-matched from its assembly shape

struct T_func_00b18c10 { void m(); };
extern T_func_00b18c10 G1_func_00b18c10;
void func_00b18c10()
{
    G1_func_00b18c10.m();
}

// roc 2012-06 00b18840  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18840
//
// 00b18840  b93863e300           mov ecx, 0xe36338
// 00b18845  e9a696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18840 { void m(); };
extern T_func_00b18840 G1_func_00b18840;
void func_00b18840()
{
    G1_func_00b18840.m();
}

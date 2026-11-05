// roc 2012-06 00b18850  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18850
//
// 00b18850  b9f862e300           mov ecx, 0xe362f8
// 00b18855  e99696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18850 { void m(); };
extern T_func_00b18850 G1_func_00b18850;
void func_00b18850()
{
    G1_func_00b18850.m();
}

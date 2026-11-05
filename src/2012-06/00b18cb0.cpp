// roc 2012-06 00b18cb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18cb0
//
// 00b18cb0  b90875e300           mov ecx, 0xe37508
// 00b18cb5  e986c8c4ff           jmp 0x765540
// auto-matched from its assembly shape

struct T_func_00b18cb0 { void m(); };
extern T_func_00b18cb0 G1_func_00b18cb0;
void func_00b18cb0()
{
    G1_func_00b18cb0.m();
}

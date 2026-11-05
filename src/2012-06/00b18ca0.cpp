// roc 2012-06 00b18ca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18ca0
//
// 00b18ca0  b98875e300           mov ecx, 0xe37588
// 00b18ca5  e94692a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18ca0 { void m(); };
extern T_func_00b18ca0 G1_func_00b18ca0;
void func_00b18ca0()
{
    G1_func_00b18ca0.m();
}

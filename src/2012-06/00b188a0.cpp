// roc 2012-06 00b188a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b188a0
//
// 00b188a0  b9785ee300           mov ecx, 0xe35e78
// 00b188a5  e94696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b188a0 { void m(); };
extern T_func_00b188a0 G1_func_00b188a0;
void func_00b188a0()
{
    G1_func_00b188a0.m();
}

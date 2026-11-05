// roc 2012-06 00b1daa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1daa0
//
// 00b1daa0  b928efe400           mov ecx, 0xe4ef28
// 00b1daa5  e94644a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1daa0 { void m(); };
extern T_func_00b1daa0 G1_func_00b1daa0;
void func_00b1daa0()
{
    G1_func_00b1daa0.m();
}

// roc 2012-06 00b1dd00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd00
//
// 00b1dd00  b948f8e400           mov ecx, 0xe4f848
// 00b1dd05  e9361dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dd00 { void m(); };
extern T_func_00b1dd00 G1_func_00b1dd00;
void func_00b1dd00()
{
    G1_func_00b1dd00.m();
}

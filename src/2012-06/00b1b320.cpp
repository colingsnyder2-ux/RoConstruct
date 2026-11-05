// roc 2012-06 00b1b320  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b320
//
// 00b1b320  b998a4e300           mov ecx, 0xe3a498
// 00b1b325  e946468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b320 { void m(); };
extern T_func_00b1b320 G1_func_00b1b320;
void func_00b1b320()
{
    G1_func_00b1b320.m();
}

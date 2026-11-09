// roc 2012-06 00b114b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114b0
//
// 00b114b0  b92064e100           mov ecx, 0xe16420
// 00b114b5  e946218fff           jmp 0x403600
// auto-matched from its assembly shape

struct T_func_00b114b0 { void m(); };
extern T_func_00b114b0 G1_func_00b114b0;
void func_00b114b0()
{
    G1_func_00b114b0.m();
}

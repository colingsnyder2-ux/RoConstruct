// roc 2012-06 00b12480  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12480
//
// 00b12480  b9f094e100           mov ecx, 0xe194f0
// 00b12485  e9e6d48fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12480 { void m(); };
extern T_func_00b12480 G1_func_00b12480;
void func_00b12480()
{
    G1_func_00b12480.m();
}

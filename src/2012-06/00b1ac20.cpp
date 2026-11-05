// roc 2012-06 00b1ac20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac20
//
// 00b1ac20  b9187ae400           mov ecx, 0xe47a18
// 00b1ac25  e9464d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac20 { void m(); };
extern T_func_00b1ac20 G1_func_00b1ac20;
void func_00b1ac20()
{
    G1_func_00b1ac20.m();
}

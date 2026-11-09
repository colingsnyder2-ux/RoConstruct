// roc 2012-06 00b1ae20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae20
//
// 00b1ae20  b9183de400           mov ecx, 0xe43d18
// 00b1ae25  e9464b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae20 { void m(); };
extern T_func_00b1ae20 G1_func_00b1ae20;
void func_00b1ae20()
{
    G1_func_00b1ae20.m();
}

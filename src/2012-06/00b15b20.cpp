// roc 2012-06 00b15b20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15b20
//
// 00b15b20  b920ace200           mov ecx, 0xe2ac20
// 00b15b25  e9469e8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15b20 { void m(); };
extern T_func_00b15b20 G1_func_00b15b20;
void func_00b15b20()
{
    G1_func_00b15b20.m();
}

// roc 2012-06 00b14b20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b20
//
// 00b14b20  b9d877e200           mov ecx, 0xe277d8
// 00b14b25  e946ae8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b20 { void m(); };
extern T_func_00b14b20 G1_func_00b14b20;
void func_00b14b20()
{
    G1_func_00b14b20.m();
}

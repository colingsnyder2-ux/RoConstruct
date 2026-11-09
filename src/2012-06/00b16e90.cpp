// roc 2012-06 00b16e90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e90
//
// 00b16e90  b9f400e300           mov ecx, 0xe300f4
// 00b16e95  e92672bcff           jmp 0x6de0c0
// auto-matched from its assembly shape

struct T_func_00b16e90 { void m(); };
extern T_func_00b16e90 G1_func_00b16e90;
void func_00b16e90()
{
    G1_func_00b16e90.m();
}

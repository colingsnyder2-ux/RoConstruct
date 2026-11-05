// roc 2012-06 00b1fa90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa90
//
// 00b1fa90  b94034e500           mov ecx, 0xe53440
// 00b1fa95  e95624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa90 { void m(); };
extern T_func_00b1fa90 G1_func_00b1fa90;
void func_00b1fa90()
{
    G1_func_00b1fa90.m();
}

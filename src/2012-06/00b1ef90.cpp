// roc 2012-06 00b1ef90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef90
//
// 00b1ef90  b9b81ae500           mov ecx, 0xe51ab8
// 00b1ef95  e9562fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1ef90 { void m(); };
extern T_func_00b1ef90 G1_func_00b1ef90;
void func_00b1ef90()
{
    G1_func_00b1ef90.m();
}

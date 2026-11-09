// roc 2012-06 00b15920  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15920
//
// 00b15920  b980a7e200           mov ecx, 0xe2a780
// 00b15925  e926a0bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b15920 { void m(); };
extern T_func_00b15920 G1_func_00b15920;
void func_00b15920()
{
    G1_func_00b15920.m();
}

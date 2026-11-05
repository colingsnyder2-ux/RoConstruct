// roc 2012-06 00b1b690  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b690
//
// 00b1b690  b9508de400           mov ecx, 0xe48d50
// 00b1b695  e95668a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b690 { void m(); };
extern T_func_00b1b690 G1_func_00b1b690;
void func_00b1b690()
{
    G1_func_00b1b690.m();
}

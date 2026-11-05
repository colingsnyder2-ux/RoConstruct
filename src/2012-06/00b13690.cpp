// roc 2012-06 00b13690  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13690
//
// 00b13690  b92008e200           mov ecx, 0xe20820
// 00b13695  e956e8a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13690 { void m(); };
extern T_func_00b13690 G1_func_00b13690;
void func_00b13690()
{
    G1_func_00b13690.m();
}

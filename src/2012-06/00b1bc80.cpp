// roc 2012-06 00b1bc80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bc80
//
// 00b1bc80  b9b897e400           mov ecx, 0xe497b8
// 00b1bc85  e96662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bc80 { void m(); };
extern T_func_00b1bc80 G1_func_00b1bc80;
void func_00b1bc80()
{
    G1_func_00b1bc80.m();
}

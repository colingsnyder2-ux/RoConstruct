// roc 2012-06 00b1fe00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fe00
//
// 00b1fe00  b9883be500           mov ecx, 0xe53b88
// 00b1fe05  e9e620a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fe00 { void m(); };
extern T_func_00b1fe00 G1_func_00b1fe00;
void func_00b1fe00()
{
    G1_func_00b1fe00.m();
}

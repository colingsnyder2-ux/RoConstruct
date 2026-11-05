// roc 2012-06 00b1de00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de00
//
// 00b1de00  b948f7e400           mov ecx, 0xe4f748
// 00b1de05  e96633b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1de00 { void m(); };
extern T_func_00b1de00 G1_func_00b1de00;
void func_00b1de00()
{
    G1_func_00b1de00.m();
}

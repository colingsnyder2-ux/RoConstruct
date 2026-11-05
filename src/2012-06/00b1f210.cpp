// roc 2012-06 00b1f210  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f210
//
// 00b1f210  b9d020e500           mov ecx, 0xe520d0
// 00b1f215  e98661d6ff           jmp 0x8853a0
// auto-matched from its assembly shape

struct T_func_00b1f210 { void m(); };
extern T_func_00b1f210 G1_func_00b1f210;
void func_00b1f210()
{
    G1_func_00b1f210.m();
}

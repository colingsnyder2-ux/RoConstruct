// roc 2012-06 00b21270  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21270
//
// 00b21270  b9c46ae500           mov ecx, 0xe56ac4
// 00b21275  e96615a5ff           jmp 0x5727e0
// auto-matched from its assembly shape

struct T_func_00b21270 { void m(); };
extern T_func_00b21270 G1_func_00b21270;
void func_00b21270()
{
    G1_func_00b21270.m();
}

// roc 2012-06 00b1da70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da70
//
// 00b1da70  b908f1e400           mov ecx, 0xe4f108
// 00b1da75  e9c61fd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1da70 { void m(); };
extern T_func_00b1da70 G1_func_00b1da70;
void func_00b1da70()
{
    G1_func_00b1da70.m();
}

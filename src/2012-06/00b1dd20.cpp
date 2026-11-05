// roc 2012-06 00b1dd20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd20
//
// 00b1dd20  b908f7e400           mov ecx, 0xe4f708
// 00b1dd25  e9161dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dd20 { void m(); };
extern T_func_00b1dd20 G1_func_00b1dd20;
void func_00b1dd20()
{
    G1_func_00b1dd20.m();
}

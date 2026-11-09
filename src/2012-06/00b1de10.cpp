// roc 2012-06 00b1de10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de10
//
// 00b1de10  b9d0f5e400           mov ecx, 0xe4f5d0
// 00b1de15  e9261cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1de10 { void m(); };
extern T_func_00b1de10 G1_func_00b1de10;
void func_00b1de10()
{
    G1_func_00b1de10.m();
}

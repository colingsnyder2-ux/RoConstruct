// roc 2012-06 00b1be60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be60
//
// 00b1be60  b95896e400           mov ecx, 0xe49658
// 00b1be65  e98660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1be60 { void m(); };
extern T_func_00b1be60 G1_func_00b1be60;
void func_00b1be60()
{
    G1_func_00b1be60.m();
}

// roc 2012-06 00b1e560  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e560
//
// 00b1e560  b95006e500           mov ecx, 0xe50650
// 00b1e565  e98639a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1e560 { void m(); };
extern T_func_00b1e560 G1_func_00b1e560;
void func_00b1e560()
{
    G1_func_00b1e560.m();
}

// roc 2012-06 00b17150  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17150
//
// 00b17150  b95804e300           mov ecx, 0xe30458
// 00b17155  e996ada7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17150 { void m(); };
extern T_func_00b17150 G1_func_00b17150;
void func_00b17150()
{
    G1_func_00b17150.m();
}

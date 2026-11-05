// roc 2012-06 00b17ce0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17ce0
//
// 00b17ce0  b96835e300           mov ecx, 0xe33568
// 00b17ce5  e9b692c1ff           jmp 0x730fa0
// auto-matched from its assembly shape

struct T_func_00b17ce0 { void m(); };
extern T_func_00b17ce0 G1_func_00b17ce0;
void func_00b17ce0()
{
    G1_func_00b17ce0.m();
}

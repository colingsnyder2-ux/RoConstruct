// roc 2012-06 00af0760  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0760
//
// 00af0760  b98073e200           mov ecx, 0xe27380
// 00af0765  e9c612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0760 { void m(); };
extern T_func_00af0760 G1_func_00af0760;
void func_00af0760()
{
    G1_func_00af0760.m();
}

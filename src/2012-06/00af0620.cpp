// roc 2012-06 00af0620  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0620
//
// 00af0620  b9d05be200           mov ecx, 0xe25bd0
// 00af0625  e90614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0620 { void m(); };
extern T_func_00af0620 G1_func_00af0620;
void func_00af0620()
{
    G1_func_00af0620.m();
}

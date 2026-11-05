// roc 2012-06 00af0290  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0290
//
// 00af0290  b91852e200           mov ecx, 0xe25218
// 00af0295  e99617a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0290 { void m(); };
extern T_func_00af0290 G1_func_00af0290;
void func_00af0290()
{
    G1_func_00af0290.m();
}

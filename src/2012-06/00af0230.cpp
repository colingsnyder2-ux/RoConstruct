// roc 2012-06 00af0230  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0230
//
// 00af0230  b9f84ee200           mov ecx, 0xe24ef8
// 00af0235  e9f617a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0230 { void m(); };
extern T_func_00af0230 G1_func_00af0230;
void func_00af0230()
{
    G1_func_00af0230.m();
}

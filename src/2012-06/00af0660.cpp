// roc 2012-06 00af0660  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0660
//
// 00af0660  b90c5de200           mov ecx, 0xe25d0c
// 00af0665  e9c613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0660 { void m(); };
extern T_func_00af0660 G1_func_00af0660;
void func_00af0660()
{
    G1_func_00af0660.m();
}

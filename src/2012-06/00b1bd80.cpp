// roc 2012-06 00b1bd80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bd80
//
// 00b1bd80  b9289fe400           mov ecx, 0xe49f28
// 00b1bd85  e9c6acc7ff           jmp 0x796a50
// auto-matched from its assembly shape

struct T_func_00b1bd80 { void m(); };
extern T_func_00b1bd80 G1_func_00b1bd80;
void func_00b1bd80()
{
    G1_func_00b1bd80.m();
}

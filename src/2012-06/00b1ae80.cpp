// roc 2012-06 00b1ae80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae80
//
// 00b1ae80  b9a831e400           mov ecx, 0xe431a8
// 00b1ae85  e9e64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae80 { void m(); };
extern T_func_00b1ae80 G1_func_00b1ae80;
void func_00b1ae80()
{
    G1_func_00b1ae80.m();
}

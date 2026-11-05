// roc 2012-06 00b1af80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af80
//
// 00b1af80  b92813e400           mov ecx, 0xe41328
// 00b1af85  e9e6498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af80 { void m(); };
extern T_func_00b1af80 G1_func_00b1af80;
void func_00b1af80()
{
    G1_func_00b1af80.m();
}

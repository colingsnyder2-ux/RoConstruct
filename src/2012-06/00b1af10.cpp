// roc 2012-06 00b1af10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af10
//
// 00b1af10  b98020e400           mov ecx, 0xe42080
// 00b1af15  e9564a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af10 { void m(); };
extern T_func_00b1af10 G1_func_00b1af10;
void func_00b1af10()
{
    G1_func_00b1af10.m();
}

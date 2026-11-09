// roc 2012-06 00b1ad80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad80
//
// 00b1ad80  b92850e400           mov ecx, 0xe45028
// 00b1ad85  e9e64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad80 { void m(); };
extern T_func_00b1ad80 G1_func_00b1ad80;
void func_00b1ad80()
{
    G1_func_00b1ad80.m();
}

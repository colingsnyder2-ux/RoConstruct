// roc 2012-06 00b13300  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13300
//
// 00b13300  b928e4e100           mov ecx, 0xe1e428
// 00b13305  e966c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13300 { void m(); };
extern T_func_00b13300 G1_func_00b13300;
void func_00b13300()
{
    G1_func_00b13300.m();
}

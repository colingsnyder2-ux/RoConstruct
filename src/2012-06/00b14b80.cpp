// roc 2012-06 00b14b80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b80
//
// 00b14b80  b91880e200           mov ecx, 0xe28018
// 00b14b85  e9e6ad8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b80 { void m(); };
extern T_func_00b14b80 G1_func_00b14b80;
void func_00b14b80()
{
    G1_func_00b14b80.m();
}

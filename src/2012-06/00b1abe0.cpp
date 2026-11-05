// roc 2012-06 00b1abe0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1abe0
//
// 00b1abe0  b9b881e400           mov ecx, 0xe481b8
// 00b1abe5  e9864d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1abe0 { void m(); };
extern T_func_00b1abe0 G1_func_00b1abe0;
void func_00b1abe0()
{
    G1_func_00b1abe0.m();
}

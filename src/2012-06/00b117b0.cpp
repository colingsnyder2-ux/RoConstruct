// roc 2012-06 00b117b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b117b0
//
// 00b117b0  b9207ee100           mov ecx, 0xe17e20
// 00b117b5  e9b6e18fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b117b0 { void m(); };
extern T_func_00b117b0 G1_func_00b117b0;
void func_00b117b0()
{
    G1_func_00b117b0.m();
}

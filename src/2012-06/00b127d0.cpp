// roc 2012-06 00b127d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127d0
//
// 00b127d0  b9b8a6e100           mov ecx, 0xe1a6b8
// 00b127d5  e996d18fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b127d0 { void m(); };
extern T_func_00b127d0 G1_func_00b127d0;
void func_00b127d0()
{
    G1_func_00b127d0.m();
}

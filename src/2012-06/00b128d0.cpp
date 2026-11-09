// roc 2012-06 00b128d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b128d0
//
// 00b128d0  b988abe100           mov ecx, 0xe1ab88
// 00b128d5  e996d08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b128d0 { void m(); };
extern T_func_00b128d0 G1_func_00b128d0;
void func_00b128d0()
{
    G1_func_00b128d0.m();
}

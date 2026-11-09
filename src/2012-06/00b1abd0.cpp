// roc 2012-06 00b1abd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1abd0
//
// 00b1abd0  b9a083e400           mov ecx, 0xe483a0
// 00b1abd5  e9964d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1abd0 { void m(); };
extern T_func_00b1abd0 G1_func_00b1abd0;
void func_00b1abd0()
{
    G1_func_00b1abd0.m();
}

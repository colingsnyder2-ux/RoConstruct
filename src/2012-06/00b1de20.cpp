// roc 2012-06 00b1de20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de20
//
// 00b1de20  b988f9e400           mov ecx, 0xe4f988
// 00b1de25  e9261bbcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b1de20 { void m(); };
extern T_func_00b1de20 G1_func_00b1de20;
void func_00b1de20()
{
    G1_func_00b1de20.m();
}

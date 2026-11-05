// roc 2012-06 00b175c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b175c0
//
// 00b175c0  b9381de300           mov ecx, 0xe31d38
// 00b175c5  e9a6838fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b175c0 { void m(); };
extern T_func_00b175c0 G1_func_00b175c0;
void func_00b175c0()
{
    G1_func_00b175c0.m();
}

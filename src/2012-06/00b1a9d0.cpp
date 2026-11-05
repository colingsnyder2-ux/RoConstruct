// roc 2012-06 00b1a9d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9d0
//
// 00b1a9d0  b96092e300           mov ecx, 0xe39260
// 00b1a9d5  e9e635c5ff           jmp 0x76dfc0
// auto-matched from its assembly shape

struct T_func_00b1a9d0 { void m(); };
extern T_func_00b1a9d0 G1_func_00b1a9d0;
void func_00b1a9d0()
{
    G1_func_00b1a9d0.m();
}

// roc 2012-06 00b148c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b148c0
//
// 00b148c0  b9484fe200           mov ecx, 0xe24f48
// 00b148c5  e9a6b08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b148c0 { void m(); };
extern T_func_00b148c0 G1_func_00b148c0;
void func_00b148c0()
{
    G1_func_00b148c0.m();
}

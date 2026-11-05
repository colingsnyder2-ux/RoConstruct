// roc 2012-06 00b132d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b132d0
//
// 00b132d0  b910e6e100           mov ecx, 0xe1e610
// 00b132d5  e996c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b132d0 { void m(); };
extern T_func_00b132d0 G1_func_00b132d0;
void func_00b132d0()
{
    G1_func_00b132d0.m();
}

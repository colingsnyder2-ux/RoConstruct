// roc 2012-06 00b132c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b132c0
//
// 00b132c0  b9f8e7e100           mov ecx, 0xe1e7f8
// 00b132c5  e9a6c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b132c0 { void m(); };
extern T_func_00b132c0 G1_func_00b132c0;
void func_00b132c0()
{
    G1_func_00b132c0.m();
}

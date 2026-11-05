// roc 2012-06 00b14980  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14980
//
// 00b14980  b9d854e200           mov ecx, 0xe254d8
// 00b14985  e9e6af8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14980 { void m(); };
extern T_func_00b14980 G1_func_00b14980;
void func_00b14980()
{
    G1_func_00b14980.m();
}

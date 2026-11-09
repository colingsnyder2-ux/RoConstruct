// roc 2012-06 00b1ac10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac10
//
// 00b1ac10  b9007ce400           mov ecx, 0xe47c00
// 00b1ac15  e9564d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac10 { void m(); };
extern T_func_00b1ac10 G1_func_00b1ac10;
void func_00b1ac10()
{
    G1_func_00b1ac10.m();
}

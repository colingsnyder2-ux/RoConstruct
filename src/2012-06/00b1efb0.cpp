// roc 2012-06 00b1efb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1efb0
//
// 00b1efb0  b9381de500           mov ecx, 0xe51d38
// 00b1efb5  e9860ad6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1efb0 { void m(); };
extern T_func_00b1efb0 G1_func_00b1efb0;
void func_00b1efb0()
{
    G1_func_00b1efb0.m();
}

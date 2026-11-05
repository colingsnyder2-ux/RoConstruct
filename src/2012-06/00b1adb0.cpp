// roc 2012-06 00b1adb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1adb0
//
// 00b1adb0  b9704ae400           mov ecx, 0xe44a70
// 00b1adb5  e9b64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1adb0 { void m(); };
extern T_func_00b1adb0 G1_func_00b1adb0;
void func_00b1adb0()
{
    G1_func_00b1adb0.m();
}

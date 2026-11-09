// roc 2012-06 00b1ed30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ed30
//
// 00b1ed30  b97017e500           mov ecx, 0xe51770
// 00b1ed35  e9060dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ed30 { void m(); };
extern T_func_00b1ed30 G1_func_00b1ed30;
void func_00b1ed30()
{
    G1_func_00b1ed30.m();
}

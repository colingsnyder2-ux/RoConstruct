// roc 2012-06 00b1db40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1db40
//
// 00b1db40  b9e8f3e400           mov ecx, 0xe4f3e8
// 00b1db45  e9f61ed6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1db40 { void m(); };
extern T_func_00b1db40 G1_func_00b1db40;
void func_00b1db40()
{
    G1_func_00b1db40.m();
}

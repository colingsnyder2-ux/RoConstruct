// roc 2012-06 00b1aeb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aeb0
//
// 00b1aeb0  b9f02be400           mov ecx, 0xe42bf0
// 00b1aeb5  e9b64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aeb0 { void m(); };
extern T_func_00b1aeb0 G1_func_00b1aeb0;
void func_00b1aeb0()
{
    G1_func_00b1aeb0.m();
}

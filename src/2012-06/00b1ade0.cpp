// roc 2012-06 00b1ade0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ade0
//
// 00b1ade0  b9b844e400           mov ecx, 0xe444b8
// 00b1ade5  e9864b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ade0 { void m(); };
extern T_func_00b1ade0 G1_func_00b1ade0;
void func_00b1ade0()
{
    G1_func_00b1ade0.m();
}

// roc 2012-06 00b1d0a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d0a0
//
// 00b1d0a0  b960dee400           mov ecx, 0xe4de60
// 00b1d0a5  e99629d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1d0a0 { void m(); };
extern T_func_00b1d0a0 G1_func_00b1d0a0;
void func_00b1d0a0()
{
    G1_func_00b1d0a0.m();
}

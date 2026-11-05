// roc 2012-06 00b124a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b124a0
//
// 00b124a0  b9689ee100           mov ecx, 0xe19e68
// 00b124a5  e9c6d48fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b124a0 { void m(); };
extern T_func_00b124a0 G1_func_00b124a0;
void func_00b124a0()
{
    G1_func_00b124a0.m();
}

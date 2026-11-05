// roc 2012-06 00b17830  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17830
//
// 00b17830  b98027e300           mov ecx, 0xe32780
// 00b17835  e936818fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17830 { void m(); };
extern T_func_00b17830 G1_func_00b17830;
void func_00b17830()
{
    G1_func_00b17830.m();
}

// roc 2012-06 00b18990  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18990
//
// 00b18990  b92865e300           mov ecx, 0xe36528
// 00b18995  e9d66f8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18990 { void m(); };
extern T_func_00b18990 G1_func_00b18990;
void func_00b18990()
{
    G1_func_00b18990.m();
}

// roc 2012-06 00b1a990  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a990
//
// 00b1a990  b92095e300           mov ecx, 0xe39520
// 00b1a995  e91640c5ff           jmp 0x76e9b0
// auto-matched from its assembly shape

struct T_func_00b1a990 { void m(); };
extern T_func_00b1a990 G1_func_00b1a990;
void func_00b1a990()
{
    G1_func_00b1a990.m();
}

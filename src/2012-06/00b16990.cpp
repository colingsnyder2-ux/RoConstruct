// roc 2012-06 00b16990  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16990
//
// 00b16990  b908ece200           mov ecx, 0xe2ec08
// 00b16995  e9a690d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16990 { void m(); };
extern T_func_00b16990 G1_func_00b16990;
void func_00b16990()
{
    G1_func_00b16990.m();
}

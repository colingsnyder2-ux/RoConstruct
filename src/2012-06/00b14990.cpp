// roc 2012-06 00b14990  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14990
//
// 00b14990  b9f052e200           mov ecx, 0xe252f0
// 00b14995  e9d6af8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14990 { void m(); };
extern T_func_00b14990 G1_func_00b14990;
void func_00b14990()
{
    G1_func_00b14990.m();
}

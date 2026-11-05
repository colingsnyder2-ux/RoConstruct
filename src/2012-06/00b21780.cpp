// roc 2012-06 00b21780  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21780
//
// 00b21780  b9689de500           mov ecx, 0xe59d68
// 00b21785  e91655f3ff           jmp 0xa56ca0
// auto-matched from its assembly shape

struct T_func_00b21780 { void m(); };
extern T_func_00b21780 G1_func_00b21780;
void func_00b21780()
{
    G1_func_00b21780.m();
}

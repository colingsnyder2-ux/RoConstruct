// roc 2012-06 00b1be30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be30
//
// 00b1be30  b9609ae400           mov ecx, 0xe49a60
// 00b1be35  e916acc7ff           jmp 0x796a50
// auto-matched from its assembly shape

struct T_func_00b1be30 { void m(); };
extern T_func_00b1be30 G1_func_00b1be30;
void func_00b1be30()
{
    G1_func_00b1be30.m();
}

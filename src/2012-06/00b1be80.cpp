// roc 2012-06 00b1be80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be80
//
// 00b1be80  b97099e400           mov ecx, 0xe49970
// 00b1be85  e9c6abc7ff           jmp 0x796a50
// auto-matched from its assembly shape

struct T_func_00b1be80 { void m(); };
extern T_func_00b1be80 G1_func_00b1be80;
void func_00b1be80()
{
    G1_func_00b1be80.m();
}

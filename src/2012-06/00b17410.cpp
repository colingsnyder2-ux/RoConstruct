// roc 2012-06 00b17410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17410
//
// 00b17410  b99816e300           mov ecx, 0xe31698
// 00b17415  e9d6aaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17410 { void m(); };
extern T_func_00b17410 G1_func_00b17410;
void func_00b17410()
{
    G1_func_00b17410.m();
}

// roc 2012-06 00b17900  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17900
//
// 00b17900  b96824e300           mov ecx, 0xe32468
// 00b17905  e936b7c0ff           jmp 0x723040
// auto-matched from its assembly shape

struct T_func_00b17900 { void m(); };
extern T_func_00b17900 G1_func_00b17900;
void func_00b17900()
{
    G1_func_00b17900.m();
}

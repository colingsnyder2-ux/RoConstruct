// roc 2012-06 00b17160  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17160
//
// 00b17160  b9d004e300           mov ecx, 0xe304d0
// 00b17165  e986ada7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17160 { void m(); };
extern T_func_00b17160 G1_func_00b17160;
void func_00b17160()
{
    G1_func_00b17160.m();
}

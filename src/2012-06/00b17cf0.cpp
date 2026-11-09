// roc 2012-06 00b17cf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17cf0
//
// 00b17cf0  b9b834e300           mov ecx, 0xe334b8
// 00b17cf5  e95690c1ff           jmp 0x730d50
// auto-matched from its assembly shape

struct T_func_00b17cf0 { void m(); };
extern T_func_00b17cf0 G1_func_00b17cf0;
void func_00b17cf0()
{
    G1_func_00b17cf0.m();
}

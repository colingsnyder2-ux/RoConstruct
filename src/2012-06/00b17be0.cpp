// roc 2012-06 00b17be0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17be0
//
// 00b17be0  b9402fe300           mov ecx, 0xe32f40
// 00b17be5  e9e66fc1ff           jmp 0x72ebd0
// auto-matched from its assembly shape

struct T_func_00b17be0 { void m(); };
extern T_func_00b17be0 G1_func_00b17be0;
void func_00b17be0()
{
    G1_func_00b17be0.m();
}

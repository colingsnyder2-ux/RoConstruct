// roc 2012-06 00b1b600  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b600
//
// 00b1b600  b9408ae400           mov ecx, 0xe48a40
// 00b1b605  e9e667c5ff           jmp 0x771df0
// auto-matched from its assembly shape

struct T_func_00b1b600 { void m(); };
extern T_func_00b1b600 G1_func_00b1b600;
void func_00b1b600()
{
    G1_func_00b1b600.m();
}

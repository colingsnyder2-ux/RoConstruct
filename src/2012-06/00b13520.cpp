// roc 2012-06 00b13520  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13520
//
// 00b13520  b9fc14e200           mov ecx, 0xe214fc
// 00b13525  e9064ba1ff           jmp 0x528030
// auto-matched from its assembly shape

struct T_func_00b13520 { void m(); };
extern T_func_00b13520 G1_func_00b13520;
void func_00b13520()
{
    G1_func_00b13520.m();
}

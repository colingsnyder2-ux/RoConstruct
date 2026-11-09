// roc 2012-06 00b17550  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17550
//
// 00b17550  b9ec18e300           mov ecx, 0xe318ec
// 00b17555  e996a9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17550 { void m(); };
extern T_func_00b17550 G1_func_00b17550;
void func_00b17550()
{
    G1_func_00b17550.m();
}

// roc 2012-06 00b18420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18420
//
// 00b18420  b97859e300           mov ecx, 0xe35978
// 00b18425  e91676d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b18420 { void m(); };
extern T_func_00b18420 G1_func_00b18420;
void func_00b18420()
{
    G1_func_00b18420.m();
}

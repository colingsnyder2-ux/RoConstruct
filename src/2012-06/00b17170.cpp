// roc 2012-06 00b17170  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17170
//
// 00b17170  b9f006e300           mov ecx, 0xe306f0
// 00b17175  e9f6878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17170 { void m(); };
extern T_func_00b17170 G1_func_00b17170;
void func_00b17170()
{
    G1_func_00b17170.m();
}

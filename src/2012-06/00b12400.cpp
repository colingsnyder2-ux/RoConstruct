// roc 2012-06 00b12400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12400
//
// 00b12400  b9e092e100           mov ecx, 0xe192e0
// 00b12405  e9c64595ff           jmp 0x4669d0
// auto-matched from its assembly shape

struct T_func_00b12400 { void m(); };
extern T_func_00b12400 G1_func_00b12400;
void func_00b12400()
{
    G1_func_00b12400.m();
}

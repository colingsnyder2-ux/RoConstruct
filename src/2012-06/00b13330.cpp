// roc 2012-06 00b13330  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13330
//
// 00b13330  b9e8e9e100           mov ecx, 0xe1e9e8
// 00b13335  e936c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13330 { void m(); };
extern T_func_00b13330 G1_func_00b13330;
void func_00b13330()
{
    G1_func_00b13330.m();
}

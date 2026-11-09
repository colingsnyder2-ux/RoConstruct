// roc 2012-06 00b1b080  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b080
//
// 00b1b080  b9a8f4e300           mov ecx, 0xe3f4a8
// 00b1b085  e9e6488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b080 { void m(); };
extern T_func_00b1b080 G1_func_00b1b080;
void func_00b1b080()
{
    G1_func_00b1b080.m();
}

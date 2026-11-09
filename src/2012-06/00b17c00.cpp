// roc 2012-06 00b17c00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17c00
//
// 00b17c00  b9f02fe300           mov ecx, 0xe32ff0
// 00b17c05  e9667d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17c00 { void m(); };
extern T_func_00b17c00 G1_func_00b17c00;
void func_00b17c00()
{
    G1_func_00b17c00.m();
}

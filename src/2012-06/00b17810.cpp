// roc 2012-06 00b17810  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17810
//
// 00b17810  b96829e300           mov ecx, 0xe32968
// 00b17815  e956818fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17810 { void m(); };
extern T_func_00b17810 G1_func_00b17810;
void func_00b17810()
{
    G1_func_00b17810.m();
}

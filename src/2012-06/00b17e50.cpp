// roc 2012-06 00b17e50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17e50
//
// 00b17e50  b9783fe300           mov ecx, 0xe33f78
// 00b17e55  e9167b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17e50 { void m(); };
extern T_func_00b17e50 G1_func_00b17e50;
void func_00b17e50()
{
    G1_func_00b17e50.m();
}

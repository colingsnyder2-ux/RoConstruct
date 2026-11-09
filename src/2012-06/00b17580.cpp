// roc 2012-06 00b17580  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17580
//
// 00b17580  b9341ae300           mov ecx, 0xe31a34
// 00b17585  e966a9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17580 { void m(); };
extern T_func_00b17580 G1_func_00b17580;
void func_00b17580()
{
    G1_func_00b17580.m();
}

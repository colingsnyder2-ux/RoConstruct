// roc 2012-06 00b1fc80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fc80
//
// 00b1fc80  b92838e500           mov ecx, 0xe53828
// 00b1fc85  e96622a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fc80 { void m(); };
extern T_func_00b1fc80 G1_func_00b1fc80;
void func_00b1fc80()
{
    G1_func_00b1fc80.m();
}

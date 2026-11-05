// roc 2012-06 00b17130  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17130
//
// 00b17130  b96802e300           mov ecx, 0xe30268
// 00b17135  e936888fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17130 { void m(); };
extern T_func_00b17130 G1_func_00b17130;
void func_00b17130()
{
    G1_func_00b17130.m();
}

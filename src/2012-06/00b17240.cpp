// roc 2012-06 00b17240  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17240
//
// 00b17240  b9700ce300           mov ecx, 0xe30c70
// 00b17245  e926878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17240 { void m(); };
extern T_func_00b17240 G1_func_00b17240;
void func_00b17240()
{
    G1_func_00b17240.m();
}

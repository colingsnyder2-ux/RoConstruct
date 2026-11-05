// roc 2012-06 00b18130  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18130
//
// 00b18130  b9a049e300           mov ecx, 0xe349a0
// 00b18135  e936788fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18130 { void m(); };
extern T_func_00b18130 G1_func_00b18130;
void func_00b18130()
{
    G1_func_00b18130.m();
}

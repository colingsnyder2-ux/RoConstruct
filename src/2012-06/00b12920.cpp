// roc 2012-06 00b12920  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12920
//
// 00b12920  b99cc1e100           mov ecx, 0xe1c19c
// 00b12925  e9f6019aff           jmp 0x4b2b20
// auto-matched from its assembly shape

struct T_func_00b12920 { void m(); };
extern T_func_00b12920 G1_func_00b12920;
void func_00b12920()
{
    G1_func_00b12920.m();
}

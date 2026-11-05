// roc 2012-06 00b1fa80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa80
//
// 00b1fa80  b91035e500           mov ecx, 0xe53510
// 00b1fa85  e96624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa80 { void m(); };
extern T_func_00b1fa80 G1_func_00b1fa80;
void func_00b1fa80()
{
    G1_func_00b1fa80.m();
}

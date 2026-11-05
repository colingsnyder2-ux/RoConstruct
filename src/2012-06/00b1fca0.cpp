// roc 2012-06 00b1fca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fca0
//
// 00b1fca0  b9a837e500           mov ecx, 0xe537a8
// 00b1fca5  e996fdd5ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1fca0 { void m(); };
extern T_func_00b1fca0 G1_func_00b1fca0;
void func_00b1fca0()
{
    G1_func_00b1fca0.m();
}

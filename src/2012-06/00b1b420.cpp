// roc 2012-06 00b1b420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b420
//
// 00b1b420  b94887e400           mov ecx, 0xe48748
// 00b1b425  e92608c6ff           jmp 0x77bc50
// auto-matched from its assembly shape

struct T_func_00b1b420 { void m(); };
extern T_func_00b1b420 G1_func_00b1b420;
void func_00b1b420()
{
    G1_func_00b1b420.m();
}

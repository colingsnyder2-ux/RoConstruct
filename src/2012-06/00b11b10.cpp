// roc 2012-06 00b11b10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b10
//
// 00b11b10  b96089e100           mov ecx, 0xe18960
// 00b11b15  e966d592ff           jmp 0x43f080
// auto-matched from its assembly shape

struct T_func_00b11b10 { void m(); };
extern T_func_00b11b10 G1_func_00b11b10;
void func_00b11b10()
{
    G1_func_00b11b10.m();
}

// roc 2012-06 00b11a90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11a90
//
// 00b11a90  b94089e100           mov ecx, 0xe18940
// 00b11a95  e966fc92ff           jmp 0x441700
// auto-matched from its assembly shape

struct T_func_00b11a90 { void m(); };
extern T_func_00b11a90 G1_func_00b11a90;
void func_00b11a90()
{
    G1_func_00b11a90.m();
}

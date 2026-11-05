// roc 2012-06 00b11490  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11490
//
// 00b11490  b91864e100           mov ecx, 0xe16418
// 00b11495  e9062b8fff           jmp 0x403fa0
// auto-matched from its assembly shape

struct T_func_00b11490 { void m(); };
extern T_func_00b11490 G1_func_00b11490;
void func_00b11490()
{
    G1_func_00b11490.m();
}

// roc 2012-06 00b17d10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d10
//
// 00b17d10  b91836e300           mov ecx, 0xe33618
// 00b17d15  e9567c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17d10 { void m(); };
extern T_func_00b17d10 G1_func_00b17d10;
void func_00b17d10()
{
    G1_func_00b17d10.m();
}

// roc 2012-06 00b12900  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12900
//
// 00b12900  b9c8bde100           mov ecx, 0xe1bdc8
// 00b12905  e966d08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12900 { void m(); };
extern T_func_00b12900 G1_func_00b12900;
void func_00b12900()
{
    G1_func_00b12900.m();
}

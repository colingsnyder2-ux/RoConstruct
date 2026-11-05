// roc 2012-06 00b17230  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17230
//
// 00b17230  b9580ee300           mov ecx, 0xe30e58
// 00b17235  e936878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17230 { void m(); };
extern T_func_00b17230 G1_func_00b17230;
void func_00b17230()
{
    G1_func_00b17230.m();
}

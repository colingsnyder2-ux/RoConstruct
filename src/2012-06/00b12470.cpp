// roc 2012-06 00b12470  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12470
//
// 00b12470  b9108ee100           mov ecx, 0xe18e10
// 00b12475  e9e63595ff           jmp 0x465a60
// auto-matched from its assembly shape

struct T_func_00b12470 { void m(); };
extern T_func_00b12470 G1_func_00b12470;
void func_00b12470()
{
    G1_func_00b12470.m();
}

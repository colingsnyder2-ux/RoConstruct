// roc 2012-06 00b127b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127b0
//
// 00b127b0  b968a6e100           mov ecx, 0xe1a668
// 00b127b5  e9462897ff           jmp 0x485000
// auto-matched from its assembly shape

struct T_func_00b127b0 { void m(); };
extern T_func_00b127b0 G1_func_00b127b0;
void func_00b127b0()
{
    G1_func_00b127b0.m();
}

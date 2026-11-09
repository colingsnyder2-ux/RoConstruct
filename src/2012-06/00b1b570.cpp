// roc 2012-06 00b1b570  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b570
//
// 00b1b570  b9f48ae400           mov ecx, 0xe48af4
// 00b1b575  e9e694c5ff           jmp 0x774a60
// auto-matched from its assembly shape

struct T_func_00b1b570 { void m(); };
extern T_func_00b1b570 G1_func_00b1b570;
void func_00b1b570()
{
    G1_func_00b1b570.m();
}

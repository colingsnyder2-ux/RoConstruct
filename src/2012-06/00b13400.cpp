// roc 2012-06 00b13400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13400
//
// 00b13400  b9200de200           mov ecx, 0xe20d20
// 00b13405  e936c6d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13400 { void m(); };
extern T_func_00b13400 G1_func_00b13400;
void func_00b13400()
{
    G1_func_00b13400.m();
}

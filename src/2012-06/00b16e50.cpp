// roc 2012-06 00b16e50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e50
//
// 00b16e50  b960eee200           mov ecx, 0xe2ee60
// 00b16e55  e9e68bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16e50 { void m(); };
extern T_func_00b16e50 G1_func_00b16e50;
void func_00b16e50()
{
    G1_func_00b16e50.m();
}

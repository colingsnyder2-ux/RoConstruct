// roc 2012-06 00b1ef70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef70
//
// 00b1ef70  b9b81be500           mov ecx, 0xe51bb8
// 00b1ef75  e9c60ad6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ef70 { void m(); };
extern T_func_00b1ef70 G1_func_00b1ef70;
void func_00b1ef70()
{
    G1_func_00b1ef70.m();
}

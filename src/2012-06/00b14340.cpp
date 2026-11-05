// roc 2012-06 00b14340  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14340
//
// 00b14340  b9003de200           mov ecx, 0xe23d00
// 00b14345  e9a6dba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14340 { void m(); };
extern T_func_00b14340 G1_func_00b14340;
void func_00b14340()
{
    G1_func_00b14340.m();
}

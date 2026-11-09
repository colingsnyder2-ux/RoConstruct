// roc 2012-06 00b14850  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14850
//
// 00b14850  b99c4ee200           mov ecx, 0xe24e9c
// 00b14855  e94687a6ff           jmp 0x57cfa0
// auto-matched from its assembly shape

struct T_func_00b14850 { void m(); };
extern T_func_00b14850 G1_func_00b14850;
void func_00b14850()
{
    G1_func_00b14850.m();
}

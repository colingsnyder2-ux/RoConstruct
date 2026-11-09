// roc 2012-06 00b12460  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12460
//
// 00b12460  b9c08ee100           mov ecx, 0xe18ec0
// 00b12465  e9063895ff           jmp 0x465c70
// auto-matched from its assembly shape

struct T_func_00b12460 { void m(); };
extern T_func_00b12460 G1_func_00b12460;
void func_00b12460()
{
    G1_func_00b12460.m();
}

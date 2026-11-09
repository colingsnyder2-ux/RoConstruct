// roc 2012-06 00aefda0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aefda0
//
// 00aefda0  b90046e200           mov ecx, 0xe24600
// 00aefda5  e9861ca7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aefda0 { void m(); };
extern T_func_00aefda0 G1_func_00aefda0;
void func_00aefda0()
{
    G1_func_00aefda0.m();
}

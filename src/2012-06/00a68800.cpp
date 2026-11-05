// roc 2012-06 00a68800  unit: CXTShadowHook  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a68800
//
// 00a68800  e98bffffff           jmp 0xa68790
// auto-matched from its assembly shape

extern void G1_func_00a68800();
void func_00a68800()
{
    G1_func_00a68800();
}

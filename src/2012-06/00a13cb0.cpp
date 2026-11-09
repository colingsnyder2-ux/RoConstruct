// roc 2012-06 00a13cb0  unit: DummyJob  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a13cb0
//
// 00a13cb0  b801000000           mov eax, 1
// 00a13cb5  c3                   ret 
// auto-matched from its assembly shape

int func_00a13cb0()
{
    return 1;
}

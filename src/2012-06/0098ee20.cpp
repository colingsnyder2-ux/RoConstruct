// roc 2012-06 0098ee20  unit: CInstanceRecord::CNameItem  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098ee20
//
// 0098ee20  b801000000           mov eax, 1
// 0098ee25  c20800               ret 8
// auto-matched from its assembly shape

struct S_func_0098ee20 {

    int f(int a1, int a2);
};
int S_func_0098ee20::f(int a1, int a2)
{
    return 1;
}

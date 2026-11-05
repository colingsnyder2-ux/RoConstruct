// roc 2012-06 00908a20  unit: RBX::Ball  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00908a20
//
// 00908a20  b804000000           mov eax, 4
// 00908a25  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00908a20 {

    unsigned int f(int a1);
};
unsigned int S_func_00908a20::f(int a1)
{
    return 4u;
}

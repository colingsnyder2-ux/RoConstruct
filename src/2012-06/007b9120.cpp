// roc 2012-06 007b9120  unit: RBX::Ball  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b9120
//
// 007b9120  32c0                 xor al, al
// 007b9122  c21400               ret 0x14
// auto-matched from its assembly shape

struct S_func_007b9120 {

    bool f(int a1, int a2, int a3, int a4, int a5);
};
bool S_func_007b9120::f(int a1, int a2, int a3, int a4, int a5)
{
    return false;
}

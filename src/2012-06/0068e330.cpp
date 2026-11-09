// roc 2012-06 0068e330  unit: RBX::ModelInstance  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0068e330
//
// 0068e330  32c0                 xor al, al
// 0068e332  c20c00               ret 0xc
// auto-matched from its assembly shape

struct S_func_0068e330 {

    bool f(int a1, int a2, int a3);
};
bool S_func_0068e330::f(int a1, int a2, int a3)
{
    return false;
}

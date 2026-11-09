// roc 2012-06 006bf080  unit: RBX::PrismBuilder  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006bf080
//
// 006bf080  32c0                 xor al, al
// 006bf082  c20800               ret 8
// auto-matched from its assembly shape

struct S_func_006bf080 {

    bool f(int a1, int a2);
};
bool S_func_006bf080::f(int a1, int a2)
{
    return false;
}

// roc 2012-06 007a9d30  unit: RBX::StarterGuiService  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a9d30
//
// 007a9d30  32c0                 xor al, al
// 007a9d32  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_007a9d30 {

    bool f(int a1);
};
bool S_func_007a9d30::f(int a1)
{
    return false;
}

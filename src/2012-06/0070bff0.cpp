// roc 2012-06 0070bff0  unit: RBX::SpanningTree  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070bff0
//
// 0070bff0  b001                 mov al, 1
// 0070bff2  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0070bff0 {

    bool f(int a1);
};
bool S_func_0070bff0::f(int a1)
{
    return true;
}

// roc 2012-06 005a2ee0  unit: RBX::JavaScript::VMarshalledFunction::?$sp_counted_impl_p  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a2ee0
//
// 005a2ee0  33c0                 xor eax, eax
// 005a2ee2  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_005a2ee0 {

    int f(int a1);
};
int S_func_005a2ee0::f(int a1)
{
    return 0;
}

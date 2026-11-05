// roc 2012-06 00a7be12  unit: CXTIconHandle  size: 3 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7be12
//
// 00a7be12  8bc1                 mov eax, ecx
// 00a7be14  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a7be12 {

    void* f();
};
void* S_func_00a7be12::f()
{
    return this;
}

// roc 2012-06 0071ee10  unit: RBX::ArrowToolBase  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ee10
//
// 0071ee10  8bc1                 mov eax, ecx
// 0071ee12  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0071ee10 {

    void* f(int a1);
};
void* S_func_0071ee10::f(int a1)
{
    return this;
}

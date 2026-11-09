// roc 2012-06 009f5d00  unit: RBX::Kernel  size: 3 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f5d00
//
// 009f5d00  8bc1                 mov eax, ecx
// 009f5d02  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f5d00 {

    void* f();
};
void* S_func_009f5d00::f()
{
    return this;
}

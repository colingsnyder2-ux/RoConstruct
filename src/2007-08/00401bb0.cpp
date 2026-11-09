// from server: 100% by colin
struct VCWorkspace_CComObject {
    void method_401bb0(int, int);
};

void VCWorkspace_CComObject::method_401bb0(int a, int b) {
    int* p;
    if (a != 0) {
        p = (int*)(a - 0xc);
    } else {
        p = 0;
    }
    int* vt = (int*)*p;
    void (__stdcall *fn)(int*, void*, int) = (void (__stdcall *)(int*, void*, int))vt[0];
    fn(p, (void*)0x784be4, b);
}

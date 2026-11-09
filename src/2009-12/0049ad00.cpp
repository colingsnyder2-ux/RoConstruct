// from server: 62% by atomic.potato
extern "C" void* __cdecl sub_7F4CE6(void*, void*, unsigned int);

struct RBX_MeshKeyBase {
    void* f(unsigned int, unsigned int);
};

void* RBX_MeshKeyBase::f(unsigned int a, unsigned int b) {
    unsigned int size = 0x2c;
    if (a == 0) {
        return 0;
    }
    unsigned int n = a;
    unsigned int* p;
    if (n > 0x2c) {
        p = &n;
    } else {
        p = &size;
    }
    unsigned int v = *p;
    sub_7F4CE6(&size, (void*)v, n);
    return (void*)v;
}

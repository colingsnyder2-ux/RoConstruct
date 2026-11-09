// from server: 100% by atomic.potato
// roc 2010-06 00908cf0  unit: Ogre::RbxCluster::RbxPartBinding  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00908cf0

extern "C" void* __cdecl operator_new(unsigned int);

struct RbxPartBinding {
    int f();
};

int RbxPartBinding::f() {
    char* p = (char*)operator_new(0x60);
    if (p) {
        *(int*)p = 0;
    }
    int* q = (int*)(p + 4);
    if (q) {
        *q = 0;
    }
    int* r = (int*)(p + 8);
    if (r) {
        *r = 0;
    }
    p[0x5c] = 1;
    p[0x5d] = 0;
    return (int)p;
}

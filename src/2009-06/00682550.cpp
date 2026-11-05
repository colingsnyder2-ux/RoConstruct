// from server: 100% by why2
// roc 2009-06 00682550  unit: RBX::Sky  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00682550

struct Sky {
    void* ptr;
    int index;
    int get();
};

int Sky::get() {
    int i = index;
    char* p = (char*)ptr;
    int* arr = *(int**)(p + 0x118);
    return arr[i + 63];
}

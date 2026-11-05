// from server: 70% by atomic.potato
struct S {
    char pad0[8];
    int (__cdecl *fn)(void*, void*);
    int offset_c;
    int offset_10;
    int method(void* a, void* b);
};

int S::method(void* a, void* b) {
    char* p = (char*)a;
    if (p != 0) {
        p -= 0x1c;
    } else {
        p = 0;
    }
    int idx = *(int*)(this->offset_10 + 0);
    int* base = *(int**)(p + 0x84);
    int val = base[idx];
    val += this->offset_c;
    int (*f)(void*, void*) = this->fn;
    void* arg = (void*)(val + (int)p + 0x84);
    return f(arg, b);
}

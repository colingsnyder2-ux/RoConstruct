// from server: 52% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(void*, float);
    int offset1c;
    int offset20;
    int method(int, float*);
};

int S::method(int a, float* b) {
    S* p = (S*)a;
    if (p) {
        p = (S*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int idx = *(int*)((char*)this + 0x20);
    float val = *b;
    int* table = *(int**)((char*)p + 0x148);
    int base = table[idx];
    base += *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(void*, float) = *(int(__stdcall**)(void*, float))((char*)this + 0x18);
    return f((void*)(base + (int)p + 0x148), val);
}

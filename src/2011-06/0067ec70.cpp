// from server: 61% by atomic.potato
struct S {
    char pad0[0x18];
    int (__stdcall *fn)(int);
    char pad1[0x20 - 0x18 - 4];
    int idx;
    int f(int, int*);
};

int S::f(int a, int* b) {
    int* p = (int*)a;
    if (p != 0) {
        p = (int*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int v = *b;
    int i = idx;
    int r = *(int*)((char*)p + 0x144);
    r = *(int*)(r + i);
    r += *(int*)((char*)this + 0x1c);
    int (__stdcall *fnptr)(int) = *(int(__stdcall**)(int))((char*)this + 0x18);
    return fnptr(r + (int)p + 0x144);
}

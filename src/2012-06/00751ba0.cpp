// from server: 60% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(void*, int);
    int off1c;
    int off20;
    int method(int a, int b);
};

int S::method(int a, int b) {
    S* p = (S*)a;
    if (p) p = (S*)((char*)p - 0x1c);
    else p = 0;
    int idx = this->off20;
    int* base = (int*)((char*)p + 0x84);
    int val = base[idx];
    val += this->off1c;
    int (__stdcall *f)(void*, int) = this->fn;
    return f((char*)p + 0x84 + val, b);
}

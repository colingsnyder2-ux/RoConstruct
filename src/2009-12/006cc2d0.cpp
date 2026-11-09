// from server: 63% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    int offset1c;
    int offset20;
    int method(int, int);
};

int S::method(int a, int b) {
    S* p;
    if (a != 0) {
        p = (S*)((char*)a - 0x1c);
    } else {
        p = 0;
    }
    unsigned char c = *(unsigned char*)b;
    int idx = *(int*)((char*)this + 0x20);
    int base = *(int*)((char*)p + 0x98);
    int val = *(int*)(base + idx);
    val += *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(int, int) = *(int(__stdcall**)(int,int))((char*)this + 0x18);
    int arg = (int)((char*)p + 0x98 + val);
    return f(arg, c);
}

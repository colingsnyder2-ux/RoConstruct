// from server: 28% by atomic.potato
struct S {
    int f();
    char pad[104];
};

int S::f()
{
    int i = 0;
    while (i < 0x10000) {
        int* p = *(int**)((char*)this + 0x68);
        p = (int*)((char*)p + i);
        if (p[1] || p[3] || p[5] || p[7])
            break;
        i += 0x20;
    }
    return 0;
}

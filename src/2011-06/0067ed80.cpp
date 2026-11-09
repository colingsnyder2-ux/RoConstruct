// from server: 58% by atomic.potato
struct S {
    char pad[0x18];
    int (__cdecl *fn)(int, int);
    char pad2[0x20 - 0x18 - 4];
    int idx;
    int f(int a, int b);
};

int S::f(int a, int b)
{
    char *p = (char*)a;
    if (p)
        p -= 0x1c;
    else
        p = 0;
    unsigned char c = *(unsigned char*)b;
    int i = *(int*)(this->pad2 + 0x20 - 0x20 + 0x20);
    int v = *(int*)(p + 0x144);
    v = *(int*)(v + i);
    v += *(int*)((char*)this + 0x1c);
    int (__cdecl *fn)(int, int) = *(int(__cdecl**)(int,int))((char*)this + 0x18);
    return fn(v + (int)(p + 0x144), c);
}

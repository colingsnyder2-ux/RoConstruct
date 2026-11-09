// from server: 20% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* v;
    void (__stdcall *fn)(void*, void*, void*);
};

struct S {
    char pad[0x38];
    int field38;
    int f(int a, int b, int c, int d);
};

int S::f(int a, int b, int c, int d)
{
    int result = 0;
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xc007a8);
        *(int*)b = 0;
        *(int*)(b + 4) = 0;
        return result;
    }
    Inner* src = (Inner*)(a - 0x1c);
    Inner tmp;
    tmp.v = 0;
    if (src->v != 0) {
        tmp.v = src->v;
        src->fn(src->v, &tmp, 0);
    }
    result = (int)&tmp;
    return ((int (__stdcall*)(int, int, int))0x68bc50)(this->field38 + (int)src, result, d);
}

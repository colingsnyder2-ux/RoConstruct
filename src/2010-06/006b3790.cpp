// from server: 19% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* vt;
    void* pad;
};

struct Outer {
    void* vt;
    char pad[0x34];
    int field38;
    int method(int a, int b, int c, int d);
};

extern "C" int __stdcall sub_6b3350(int, int, int);

int Outer::method(int a, int b, int c, int d)
{
    int local = 0;
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xc007a8);
        *(int*)b = 0;
        *(int*)(b + 4) = 0;
        return 0;
    }
    Inner* p = (Inner*)(a - 0x1c);
    Inner tmp;
    tmp.vt = 0;
    tmp.pad = 0;
    int* src = (int*)c;
    if (*src != 0) {
        tmp.vt = (void*)*src;
        void** vtbl = (void**)*src;
        void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vtbl[0];
        fn(&tmp.pad, src + 2, 0);
    }
    int r = sub_6b3350(this->field38 + (int)(a - 0x1c), (int)&tmp, d);
    return r;
}

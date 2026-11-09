// from server: 62% by atomic.potato
struct Inner {
    char pad[0xc];
    void (__stdcall *fn)(void*, int);
};

struct Outer {
    char pad[0x20];
    Inner* p20;
    void Set(int, int);
};

extern "C" void* __stdcall sub_60d1d0(void*);

void Outer::Set(int a, int b)
{
    void* v;
    if (a != 0) {
        v = sub_60d1d0((void*)a);
    } else {
        v = 0;
    }
    Inner* p = p20;
    p->fn(v, b);
}

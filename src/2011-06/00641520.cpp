// from server: 74% by atomic.potato
struct Inner {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    void* f18;
    void* f1C;
    void* f20;
};

extern "C" void* __cdecl sub_6414D0(void*);

struct S {
    char pad[0x20];
    Inner* p20;
    void Method(void* a, void* b);
};

void S::Method(void* a, void* b)
{
    void* v;
    if (a)
        v = sub_6414D0(a);
    else
        v = 0;
    Inner* p = this->p20;
    void* tmp = v;
    void (*fn)(Inner*, void*, void*) = *(void (**)(Inner*, void*, void*))((char*)*(void**)p + 0xC);
    fn(p, tmp, b);
}

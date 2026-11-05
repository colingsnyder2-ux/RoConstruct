// from server: 45% by atomic.potato
extern "C" void* __stdcall sub_718a38(unsigned int);
extern "C" void __stdcall sub_718a32(void*);

struct Holder {
    void* vfptr;
    int a;
    int b;
    int c;
};

void* __stdcall make_holder(int a, int b, int c);

void* __stdcall make_holder(int a, int b, int c)
{
    Holder* h = (Holder*)sub_718a38(0x10);
    if (h) {
        h->vfptr = (void*)0x8b60fc;
        h->a = a;
        h->b = b;
        h->c = c;
    } else {
        h = 0;
    }
    return h;
}

void* __stdcall func(int a, int b, int c, void** out)
{
    void* p = make_holder(a, b, c);
    *out = p;
    sub_718a32(0);
    return out;
}

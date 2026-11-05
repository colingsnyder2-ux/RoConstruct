// from server: 70% by atomic.potato
struct Inner {
    void* field0;
    void* field4;
    void* field8;
};

struct Outer {
    char pad0[4];
    Inner inner;
    void clear();
};

extern "C" void __stdcall sub_78e090(void*, void*, void*);
extern "C" void __stdcall sub_80a058(void*);

void Outer::clear()
{
    Inner* p = &inner;
    void* a = p->field4;
    void* b = *(void**)a;
    sub_78e090(p, &a, b);
    sub_80a058(p->field4);
    p->field4 = 0;
    p->field8 = 0;
}

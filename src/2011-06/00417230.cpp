// from server: 68% by atomic.potato
struct Inner {
    void* pad0;
    void* field4;
    void* field8;
};

struct Outer {
    char pad0[4];
    Inner inner;
    void clear();
};

extern "C" void __stdcall sub_416790(void*, void*, void*);
extern "C" void __stdcall sub_80A058(void*);

void Outer::clear()
{
    Inner* p = &inner;
    void* a = p->field8;
    void* b = *(void**)a;
    sub_416790(p, &a, b);
    sub_80A058(p->field4);
    p->field4 = 0;
    p->field8 = 0;
}

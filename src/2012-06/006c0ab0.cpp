// from server: 62% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void method(int a, int b);
};

extern "C" void __stdcall sub_743E60(void* out, void* in);

void Outer::method(int a, int b)
{
    Inner* p = inner;
    void* v = *(void**)p;
    void (*fn)(Inner*, int) = *(void (**)(Inner*, int))((char*)v + 8);
    void* tmp = 0;
    fn(p, a);
    void* result = (void*)0;
    sub_743E60(&result, &tmp);
}

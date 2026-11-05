// from server: 50% by atomic.potato
struct Inner {
    virtual void* f(int, void**);
};

struct Outer {
    char pad[0x28];
    Inner* p;
    void method(int a, int b);
};

extern "C" void* __cdecl sub_867090();
extern "C" void __cdecl sub_6c2700(void*);

void Outer::method(int a, int b)
{
    Inner* q = p;
    void* r = 0;
    void* s = q->f(a, &r);
    *(void**)&r = sub_867090();
    sub_6c2700(s);
}

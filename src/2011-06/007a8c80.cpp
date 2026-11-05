// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7a8b10(void*, int);
extern "C" void __cdecl sub_80a058(void*);

struct S {
    void f();
    char padding[0x0c];
    void* field_0c;
};

void S::f()
{
    void* p = field_0c;
    if (p) {
        sub_7a8b10(p, *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x14));
        sub_80a058(p);
    }
}

// from server: 35% by atomic.potato
struct Inner {
    char pad[0x20];
};

struct Outer {
    void* field0;
    Inner inner;
    void init(void* a, void* b);
};

extern "C" void __stdcall sub_75a4e0(void* a, void* b, void* c);
extern "C" void __stdcall sub_776990();

void Outer::init(void* a, void* b)
{
    field0 = a;
    sub_776990();
    void* p = 0;
    if (a != 0)
        p = (char*)a + 0x20;
    sub_75a4e0(&inner, p, a);
}

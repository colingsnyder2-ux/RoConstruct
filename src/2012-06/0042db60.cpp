// from server: 34% by atomic.potato
struct Inner {
    char pad0[0x20];
};

struct Outer {
    void* field0;
    Inner inner;
    void init(void* a, void* b);
};

extern "C" void __stdcall sub_42DAD0(void* a, void* b);
extern "C" void __stdcall sub_75A4E0(void* a, void* b, void* c);

void Outer::init(void* a, void* b)
{
    field0 = a;
    sub_42DAD0(&inner, b);
    void* p = 0;
    if (a != 0)
        p = (char*)a + 0x20;
    sub_75A4E0(&inner, p, a);
}

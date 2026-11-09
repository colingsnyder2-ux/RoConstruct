// from server: 34% by atomic.potato
struct Inner {
    char pad[0x20];
};

struct Outer {
    void* field0;
    Inner inner;
    void init(void* a, void* b);
};

extern "C" void __stdcall sub_006c6900(void* a, void* b);
extern "C" void __stdcall sub_0075a4e0(void* a, void* b, void* c);

void Outer::init(void* a, void* b)
{
    field0 = a;
    sub_006c6900(&inner, b);
    void* p = 0;
    if (a != 0)
        p = (char*)a + 0x20;
    sub_0075a4e0(&inner, p, a);
}

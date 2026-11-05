// from server: 33% by atomic.potato
struct Inner {
    char pad0[4];
    void method();
};

struct Outer {
    char pad0[0x38];
    Inner inner;
    char pad38[0x34];
    void* ptr;
    void cleanup();
};

extern "C" void __stdcall sub_94fa70(Inner* p);

void Outer::cleanup()
{
    Inner* p = &inner;
    do {
        p->method();
        p = (Inner*)((char*)p + 0x14);
    } while (p != (Inner*)((char*)&inner + 0x14 * 1));
}

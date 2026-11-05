// from server: 30% by atomic.potato
struct Inner {
    char pad[0x20];
};

struct Outer {
    void* field0;
    Inner* field4;
    void ctor(void* a, void* b);
};

extern "C" void __stdcall sub_75A4E0(void* a, void* b, void* c);
extern "C" void __stdcall sub_77E4B0(void* a, void* b);

void Outer::ctor(void* a, void* b) {
    field0 = a;
    sub_77E4B0(&field4, b);
    field4 = 0;
    if (a != 0) {
        field4 = (Inner*)((char*)a + 0x20);
    }
    sub_75A4E0(&field4, field4, a);
}

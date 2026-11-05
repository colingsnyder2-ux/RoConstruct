// from server: 40% by atomic.potato
struct S {
    char pad[0xb8];
    void f_006f7bc0(int);
    void g(char*);
};

extern "C" void* __stdcall sub_a404c8(void*);
extern "C" void __stdcall sub_a404d0(void*);

void S::g(char* p)
{
    char buf[0x1c];
    sub_a404c8(p);
    f_006f7bc0(1);
    sub_a404d0(buf);
}

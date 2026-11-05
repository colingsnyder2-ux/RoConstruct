// from server: 37% by atomic.potato
struct S {
    void f();
};

extern "C" void* __stdcall sub_a404c8(void*, const void*);
extern "C" void __stdcall sub_a404d0(void*);

void S::f()
{
    char buf[0x60];
    void* p = buf;
    *(void**)(buf + 0x40) = p;
    sub_a404c8(buf + 0x40, buf + 0x54);
    char tmp[0x1c];
    void* q = tmp;
    *(void**)(buf + 0x60) = q;
    sub_a404c8(buf + 0x60, buf + 0x7c);
    void* r = *(void**)(buf + 0x78);
    void* s = *(void**)(buf + 4);
    s = (char*)s + *(int*)(buf + 0x78);
    void (*fn)(void*, void*) = *(void(**)(void*, void*))buf;
    fn(s, r);
    sub_a404d0(buf + 0x28);
    sub_a404d0(buf + 0x44);
    sub_a404d0(buf + 0x60);
}

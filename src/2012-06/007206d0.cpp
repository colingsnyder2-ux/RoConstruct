// from server: 61% by atomic.potato
extern "C" void* __cdecl sub_98211A(unsigned int);
extern "C" void __cdecl sub_982114(void*);

struct S {
    void* f(void** out, int a, int b, int c);
};

void* S::f(void** out, int a, int b, int c)
{
    void* p = sub_98211A(0x18);
    if (p) {
        *(int*)p = 0xba3e68;
        *(int*)((char*)p + 8) = a;
        *(int*)((char*)p + 0xc) = b;
        *(int*)((char*)p + 0x10) = c;
    } else {
        p = 0;
    }
    *out = p;
    sub_982114(0);
    return out;
}

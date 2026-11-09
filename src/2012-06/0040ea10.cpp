// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_98211A(unsigned int);
extern "C" void __cdecl sub_40DC00(void*, void*);

struct S {
    void f();
};

void S::f()
{
    void* p = sub_98211A(0x40);
    if (p != 0) {
        sub_40DC00((char*)this - 0x3c, p);
        *(int*)((char*)p + 0x3c) = 0xb43c34;
        *(int*)((char*)p) = 0xb442b4;
        *(int*)((char*)p + 0x28) = 0xb442ac;
        *(int*)((char*)p + 0x3c) = 0xb4429c;
    }
}

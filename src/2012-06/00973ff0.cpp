// from server: 40% by atomic.potato
extern "C" void sub_864D90(void *);
extern "C" int __stdcall CloseHandle(void *);
extern "C" void __cdecl sub_982114(void *);

struct S
{
    void *field_0;
    void *field_4;
    void *field_8;
    void *field_C;
    void f();
};

void S::f()
{
    void *p = field_C;
    if (p != 0)
    {
        sub_864D90((char *)p + 8);
        void *h = field_4;
        field_4 = 0;
        if (h != 0)
            CloseHandle(h);
        sub_982114(p);
    }
}

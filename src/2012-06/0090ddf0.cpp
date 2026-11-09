// from server: 100% by atomic.potato
struct S
{
    char unused[12];
    void *p;

    void f();
};

extern "C" void __cdecl sub_90dc10(void *, void *);
extern "C" void __cdecl sub_982114(void *);

void S::f()
{
    void *p = this->p;
    if (p)
    {
        sub_90dc10(p, *(void **)((char *)p + 12));
        sub_982114(p);
    }
}

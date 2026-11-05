// from server: 56% by atomic.potato
extern "C" void __cdecl sub_401630(const char *, const char *, int);
extern "C" void __cdecl sub_676c20(void *);

struct GlobalSettings_00676d60
{
    void f();
};

void GlobalSettings_00676d60::f()
{
    void *p;
    sub_401630("tUVW", (const char *)0x00b90b80, 0);
    sub_676c20(p);
}

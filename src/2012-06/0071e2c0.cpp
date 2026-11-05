// from server: 28% by atomic.potato
struct S
{
    void* m0;
    char m4;
    char m5;
    char m6;
    char m7;
    char pad[4];
    char mC;
    int f(int, int);
};

extern "C" void* __cdecl sub_6e2f80(void*);
extern "C" void __cdecl sub_8dd120(void*, void*);
extern "C" void __cdecl sub_71c640(void*, void*, void*);
extern "C" void __cdecl sub_71e250(void*);
extern "C" void __cdecl sub_7f9d90(void*, void*, int, float);
extern "C" void __stdcall sub_b22644(void*, void*);

extern void* g_e31ffc;
extern void* g_e320a0;
extern char g_e320a5;
extern char g_e320a7;
extern char g_e320a9;
extern char g_e320ac;

int S::f(int a, int b)
{
    if (m0 == g_e31ffc || m0 == g_e320a0)
        return 1;
    if (m4 != 0)
        return m4;
    if (a == 0 || *(int*)((char*)a + 0xec) == 0)
    {
        m4 = 1;
        m6 = 1;
        m7 = 1;
        return m4;
    }
    if (m5 != 0)
        return m4;
    m5 = 1;
    char buf[0x20];
    char buf2[0x30];
    sub_b22644(&mC, buf2);
    sub_8dd120(buf, buf2);
    void* p = sub_6e2f80(buf);
    sub_8dd120(buf, p);
    sub_71c640(buf, buf2, (void*)0x71e030);
    sub_71e250(buf);
    sub_7f9d90(&mC, buf, 0, 0.0f);
    return m4;
}

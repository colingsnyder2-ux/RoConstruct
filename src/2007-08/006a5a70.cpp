// from server: 49% by colin
struct CXTPMenuBar
{
    char pad0[0x20];
    void* field20;
    void* field24;
    void* field28;
    void* field2c;
    unsigned int field30;
    unsigned int field34;

    CXTPMenuBar* construct(unsigned int, unsigned int);
};

extern "C" void* __stdcall sub_62fef6(unsigned int);
extern "C" void __stdcall sub_62ff02();
extern "C" void* __stdcall sub_630478(unsigned int, unsigned int, unsigned int);
extern "C" void __stdcall sub_67be90();
extern "C" void __stdcall sub_67a4a0(unsigned int);
extern "C" void* __stdcall sub_738352();
extern "C" void* __stdcall sub_73834c(void*);

extern "C" void* __stdcall LoadIconA(void*, const char*);

extern void* g_77ddac;
extern void* g_77edd0;

CXTPMenuBar* CXTPMenuBar::construct(unsigned int a, unsigned int b)
{
    void* p;
    void* q;
    void* r;
    unsigned int v;

    g_77ddac;
    sub_67be90();

    p = sub_62fef6(0x40);
    if (p != 0)
    {
        sub_67be90();
    }
    else
    {
        p = 0;
    }

    field20 = p;
    sub_67a4a0(b);
    field30 = a;
    field34 = 0;

    sub_62ff02();
    v = (unsigned short)a;
    field2c = LoadIconA((void*)sub_630478(v, 0xe, v), (const char*)0);

    sub_62ff02();
    q = sub_738352();
    if (q != 0)
    {
        for (;;)
        {
            sub_62ff02();
            r = sub_73834c(&q);
            if (a != *(unsigned int*)((char*)r + 0x40))
            {
                (*(void(__thiscall**)(void*, int, int))(*(void**)r))(r, 1, 0);
                (*(void(__thiscall**)(void*, int, void*))(*(void**)r))(r, 6, &field28);
                break;
            }
            if (q == 0)
                break;
        }
    }

    return this;
}

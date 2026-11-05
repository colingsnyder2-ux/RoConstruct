// from server: 39% by atomic.potato
extern "C" void __cdecl sub_40A1D0(void*);

extern "C" void* __stdcall sub_98B768(void*, void*);
extern "C" void* __stdcall sub_98B7A4(void*, void*);

struct type_info;

struct bad_cast
{
    bad_cast(const char*);
};

struct S
{
    void* f(void*);
};

void* S::f(void* a)
{
    if (a != 0)
    {
        void* p = *(void**)a;
        void* q;
        if (p != 0)
        {
            q = (*(void*(**)(void*))p)(p);
        }
        else
        {
            q = (void*)0x00B0030C;
        }
        if (sub_98B768(q, (void*)0x00B1D3B0) != 0)
        {
            void* r = *(void**)a;
            r = (char*)r + 4;
            if (r != 0)
            {
                return r;
            }
        }
    }

    char buf[8];
    sub_98B7A4(buf, (void*)0x0099FE9C);
    *(void**)(buf + 4) = (void*)0x0099FE94;
    *(void**)(buf + 16) = 0;
    sub_40A1D0(buf + 4);
    return 0;
}

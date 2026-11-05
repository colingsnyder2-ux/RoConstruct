// from server: 42% by colin
struct S_func_00466350
{
    unsigned short m0;
    unsigned short m2;
    void* m4;
    void* m8;
    unsigned int mc;
    unsigned int m10;
    void f(void* p);
};

extern "C" void __stdcall sub_62ff26(void* p);
extern "C" void* __stdcall sub_62ff32(void* p);
extern "C" int __stdcall sub_727124(void* a, const char* b, void* c, void* d);
extern "C" int __stdcall sub_72712a(void* a);
extern "C" void* __stdcall sub_727130(void* a);

extern "C" void* __stdcall sub_77dd74(void* a, void* b);
extern "C" void* __stdcall sub_77d5ac(void* a, void* b);
extern "C" void* __stdcall sub_77ddbc(void* a);

void S_func_00466350::f(void* p)
{
    if (m4 != 0)
    {
        sub_62ff26(m4);
        m4 = 0;
    }
    m10 = 0;
    m0 = 0;
    m2 = 0x4e4;
    m8 = 0;
    mc = 0;

    char buf1[16];
    char buf2[16];
    char buf3[16];
    sub_77dd74(buf1, p);
    sub_77d5ac(buf2, buf1);
    void* h = sub_727130(buf2);
    if (h != 0)
    {
        void* q = sub_62ff32(h);
        m4 = q;
        sub_77d5ac(buf3, buf2);
        if (sub_72712a(buf3) != 0)
        {
            unsigned int sz = 0;
            if (sub_727124(m4, "\\VarFileInfo\\Translation", &m10, &sz) != 0)
            {
                unsigned int sz2 = 0;
                if (sub_727124(m4, "D$0P", &m8, &sz2) != 0)
                {
                    if (sz2 >= 4)
                    {
                        unsigned short* w = (unsigned short*)m8;
                        mc = sz2 >> 2;
                        m0 = w[0];
                        m2 = w[1];
                    }
                }
            }
        }
    }
    else
    {
        if (m4 != 0)
        {
            sub_62ff26(m4);
            m4 = 0;
        }
    }
    sub_77ddbc(buf1);
}

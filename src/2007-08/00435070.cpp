// from server: 22% by colin
struct CMemberTreeView
{
    char pad0[0xf4];
    void* field_f4;
    void* field_f8;
    void* field_fc;
    void* field_100;
    void* field_104;
    void* field_108;
    void* field_10c;
    void method();
};

extern "C" void __stdcall sub_401000(unsigned int);
extern "C" void* __stdcall sub_401180(void*, int);
extern "C" void* __stdcall sub_401220(void*, void*);
extern "C" void __stdcall sub_77e9b0(void*);
extern "C" void __stdcall sub_77e6a8(void*);
extern "C" void __stdcall sub_77ddb8(void*, const char*);
extern "C" int __stdcall sub_77dcd0(void*);
extern "C" void* __stdcall sub_77dd98(void*);
extern "C" void __stdcall sub_77ddbc(void*);

extern char G_785954;
extern char G_78c9b8;
extern char G_784934;

void CMemberTreeView::method()
{
    void* v;
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    int flag;

    flag = 0;
    v = 0;

    if (field_f4)
    {
        p = (void*)0x785954;
        if (p)
        {
            p = sub_401180(p, -1);
            if (!p)
            {
                sub_401000(0x8007000e);
                p = 0;
            }
        }
        else
        {
            p = 0;
        }
        (*(void (__stdcall**)(void*, void*))(*(int*)field_f4 + 0xe4))(field_f4, p);
        sub_77e9b0(p);
    }

    if (field_f8)
    {
        q = 0;
        (*(void (__stdcall**)(void*, void**))(*(int*)field_f8 + 0x40))(field_f8, &q);
        if (q)
        {
            r = sub_401180((void*)0x78c9b8, -1);
            if (!r)
            {
                sub_401000(0x8007000e);
            }
            flag = 2;
        }
        else
        {
            r = sub_401180((void*)0x784934, -1);
            if (!r)
            {
                sub_401000(0x8007000e);
            }
            flag = 3;
        }
        (*(void (__stdcall**)(void*, void*))(*(int*)q + 0x20c))(q, r);
        if (flag & 2)
        {
            flag &= ~2;
            sub_77e9b0(r);
        }
        if (flag & 1)
        {
            flag &= ~1;
            sub_77e9b0(r);
        }
        if (q)
        {
            (*(void (__stdcall**)(void*))(*(int*)q + 8))(q);
        }
    }

    if (field_100)
    {
        if (field_fc)
        {
            sub_77e6a8((char*)field_fc + 0xec);
        }
        else
        {
            sub_77ddb8(&v, (const char*)0x785954);
        }
        s = 0;
        (*(void (__stdcall**)(void*, void**))(*(int*)field_100 + 0x40))(field_100, &s);
        if (sub_77dcd0(&v))
        {
            t = sub_401180((void*)0x78c9b8, -1);
            if (!t)
            {
                sub_401000(0x8007000e);
            }
            flag |= 4;
        }
        else
        {
            t = sub_401180((void*)0x784934, -1);
            if (!t)
            {
                sub_401000(0x8007000e);
            }
            flag |= 8;
        }
        (*(void (__stdcall**)(void*, void*))(*(int*)s + 0x20c))(s, t);
        if (flag & 8)
        {
            flag &= ~8;
            sub_77e9b0(t);
        }
        if (flag & 4)
        {
            flag &= ~4;
            sub_77e9b0(t);
        }
        if (!sub_77dcd0(&v))
        {
            if (field_104)
            {
                p = sub_401180((void*)sub_77dd98(&v), -1);
                if (!p)
                {
                    sub_401000(0x8007000e);
                }
                (*(void (__stdcall**)(void*, void*))(*(int*)field_104 + 0xe4))(field_104, p);
                sub_77e9b0(p);
            }
        }
        if (s)
        {
            (*(void (__stdcall**)(void*))(*(int*)s + 8))(s);
        }
        sub_77ddbc(&v);
    }

    if (field_108)
    {
        q = 0;
        (*(void (__stdcall**)(void*, void**))(*(int*)field_108 + 0x40))(field_108, &q);
        if (q || *((char*)q + 0xe9))
        {
            sub_401220(&v, (void*)0x78c9b8);
            flag |= 0x10;
        }
        else
        {
            r = sub_401180((void*)0x784934, -1);
            if (!r)
            {
                sub_401000(0x8007000e);
            }
            flag |= 0x20;
        }
        (*(void (__stdcall**)(void*, void*))(*(int*)q + 0x20c))(q, r);
        if (flag & 0x20)
        {
            flag &= ~0x20;
            sub_77e9b0(r);
        }
        if (flag & 0x10)
        {
            flag &= ~0x10;
            sub_77e9b0(v);
        }
        if (q)
        {
            (*(void (__stdcall**)(void*))(*(int*)q + 8))(q);
        }
    }

    if (field_10c)
    {
        q = 0;
        (*(void (__stdcall**)(void*, void**))(*(int*)field_10c + 0x40))(field_10c, &q);
        if (q && *((char*)q + 0xea))
        {
            sub_401220(&v, (void*)0x78c9b8);
            flag |= 0x40;
        }
        else
        {
            r = sub_401180((void*)0x784934, -1);
            if (!r)
            {
                sub_401000(0x8007000e);
            }
            flag |= 0x80;
        }
        (*(void (__stdcall**)(void*, void*))(*(int*)q + 0x20c))(q, r);
        if (flag & 0x80)
        {
            flag &= ~0x80;
            sub_77e9b0(r);
        }
        if (flag & 0x40)
        {
            flag &= ~0x40;
            sub_77e9b0(v);
        }
        if (q)
        {
            (*(void (__stdcall**)(void*))(*(int*)q + 8))(q);
        }
    }
}

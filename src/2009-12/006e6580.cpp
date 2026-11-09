// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void *__stdcall sub_98B6F4(void *, const char *);
extern "C" void __stdcall sub_98B6E4(void *);

struct Str
{
    void *rep;
};

extern "C" void __cdecl str_ctor(Str *, const char *);
extern "C" void __cdecl str_dtor(Str *);

extern "C" void *__cdecl sub_632B80(void *);
extern "C" void *__cdecl sub_6E6360(void *);
extern "C" void __cdecl sub_4020A0(void *, void *);

struct Inner
{
    void *vptr;
    long ref1;
    long ref2;
};

struct Outer
{
    void *vptr;
    void *field4;
};

struct S
{
    char pad[0x4c];
    void *field4c;
    void *f(void *a, void *b);
};

void *S::f(void *a, void *b)
{
    Str s;
    str_ctor(&s, (const char *)0x9daf30);
    str_dtor(&s);

    Outer *o = (Outer *)b;
    if (o->vptr == 0)
    {
        if (field4c != 0)
        {
            void *r = sub_632B80(a);
            void *p = r ? (char *)r + 0x2c : 0;
            void *q = sub_6E6360(&p);
            void *v = *(void **)q;
            q = (char *)q + 4;
            _InterlockedExchangeAdd((volatile long *)&o->field4, 0);
            o->vptr = v;
            sub_4020A0(&o->field4, q);
            Inner *in = (Inner *)0;
            if (in)
            {
                if (_InterlockedExchangeAdd(&in->ref1, -1) == 1)
                {
                    void *vt = in->vptr;
                    void (*fn)(Inner *) = *(void (**)(Inner *))((char *)vt + 4);
                    fn(in);
                }
                if (_InterlockedExchangeAdd(&in->ref2, -1) == 1)
                {
                    void *vt = in->vptr;
                    void (*fn)(Inner *) = *(void (**)(Inner *))((char *)vt + 8);
                    fn(in);
                }
            }
        }
    }
    return o->vptr;
}

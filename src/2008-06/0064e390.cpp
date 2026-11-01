// from server: 100% by king_originala
extern int __cdecl func_00583f40();
extern int __cdecl func_005fe7f0();
extern void __cdecl func_006a067a(void *);

struct Owner
{
    void *p;
    ~Owner();
    void *release();
};

inline Owner::~Owner()
{
    if (p)
        func_006a067a(p);
}

inline void *Owner::release()
{
    void *q = p;
    p = 0;
    return q;
}

extern Owner __cdecl func_0064e220(int, int, int);

struct Base
{
    unsigned long words[7];
    Base(int, int, int);
    void func_0056c650(int, int, int, int, int);
    ~Base();
};

inline Base::Base(int a, int b, int f)
{
    int first = func_00583f40();
    int second = func_005fe7f0();
    func_0056c650(second, first, a, b, f);
}

struct S : Base
{
    void *value;
    S(int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f)
    : Base(a, b, f)
{
    words[0] = 0x0084b2f8;
    words[6] = 0x0084b2f0;
    value = func_0064e220(c, d, e).release();
}

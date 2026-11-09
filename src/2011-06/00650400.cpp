// from server: 49% by atomic.potato
extern "C" int __cdecl sub_67F480();

typedef int (__stdcall *FnCmp)(void*, const char*);
typedef double (__cdecl *FnStrtod)(const char*, char**);

extern FnCmp g_cmp;
extern float* g_pf1;
extern float* g_pf2;
extern float g_fConst;
extern FnStrtod g_strtod;

struct S {
    char pad0[0x14];
    int f14;
    char pad18[4];
    int f18;
    char pad1c[4];
    char* f4;
    int check(const char* name, float* out);
};

int S::check(const char* name, float* out)
{
    if (this->f14 == 0)
        return 0;
    if (g_cmp(this, name))
    {
        *out = *g_pf1;
        return 1;
    }
    if (g_cmp(this, (const char*)0xa9a204))
    {
        *out = g_fConst - *g_pf1;
        return 1;
    }
    if (g_cmp(this, (const char*)0xa9a200))
    {
        *out = *g_pf2;
        return 1;
    }
    {
        char* p;
        if (this->f18 < 0x10)
            p = (char*)this + 4;
        else
            p = this->f4;
        *out = (float)g_strtod(p, &p);
    }
    return 1;
}

// from server: 45% by atomic.potato
extern "C" {
    float __cdecl _FInf();
    int __cdecl _snprintf(char*, unsigned int, const char*, ...);
}

struct S_string {
    char pad[0x1c];
    void ctor(const char*);
};

extern float* g_float_00b2251c;
extern void* g_call_00b22648;
extern void* g_call_00b22a48;
extern unsigned int g_xor_00b63190;
extern const char g_str_00baa8f8[];
extern const char g_str_00baa8f0[];
extern const char g_str_00baa8ec[];
extern const char g_str_00baa904[];

struct S_func_00744220 {
    S_string* __cdecl f(float* p);
};

S_string* S_func_00744220::f(float* p)
{
    float v = *p;
    float inf = *g_float_00b2251c;
    if (v == inf)
    {
        S_string* s = (S_string*)p;
        s->ctor(g_str_00baa8f8);
        return s;
    }
    if (v == -inf)
    {
        S_string* s = (S_string*)p;
        s->ctor(g_str_00baa8f0);
        return s;
    }
    if (v != 0.0f)
    {
        char buf[0x20];
        _snprintf(buf, 0x20, g_str_00baa904, (double)v);
        S_string* s = (S_string*)p;
        s->ctor(buf);
        return s;
    }
    S_string* s = (S_string*)p;
    s->ctor(g_str_00baa8ec);
    return s;
}

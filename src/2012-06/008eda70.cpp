// from server: 28% by atomic.potato
struct LuaDragger {
    int __cdecl f(int* a, int* b);
};

struct Vtbl {
    int (__thiscall *fn0)(LuaDragger*);
    int (__thiscall *fn1)(LuaDragger*, int, void*);
    int (__thiscall *fn2)(LuaDragger*, int, void*);
    int (__thiscall *fn3)(LuaDragger*, int, void*);
    int (__thiscall *fn4)(LuaDragger*, int, void*);
    int (__thiscall *fn5)(LuaDragger*, int, void*);
    int (__thiscall *fn6)(LuaDragger*, int, void*);
    int (__thiscall *fn7)(LuaDragger*, int, void*);
    int (__thiscall *fn8)(LuaDragger*, int, void*);
};

struct Vec3 {
    float x, y, z;
};

struct Value {
    int a;
    int b;
    int c;
};

extern "C" void* __stdcall G1_func_0041b1d0();
extern "C" void* __stdcall G1_func_006c5520();
extern "C" void __stdcall G1_func_00972d70(int, void*, void*);
extern "C" void __stdcall G1_func_00983144(void*, void*);

int LuaDragger::f(int* a, int* b)
{
    Vtbl* vt = *(Vtbl**)this;
    if (vt->fn0(this) < 2)
        goto Lmissing;

    {
        Vec3 v;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        if (vt->fn2(this, 2, &v))
        {
            a[0] = *(int*)&v.x;
            a[1] = *(int*)&v.y;
            a[2] = *(int*)&v.z;
            return 0;
        }
    }

    {
        Value val;
        G1_func_0041b1d0();
        if (vt->fn1(this, 2, &val))
        {
            Value* r = (Value*)G1_func_006c5520();
            b[0] = r->a;
            b[1] = r->b;
            b[2] = r->c;
            return (int)b;
        }
    }

Lmissing:
    {
        int* p = (int*)*b;
        if (p)
        {
            a[0] = p[0];
            a[1] = p[1];
            a[2] = p[2];
            return 0;
        }
    }

    G1_func_00972d70(2, (void*)0xb70754, &a);
    G1_func_00983144((void*)0xcd806c, &a);
    return 0;
}

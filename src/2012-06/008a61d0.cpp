// from server: 72% by atomic.potato
typedef int (__cdecl *Fn1)(int);
typedef int (__cdecl *Fn2)(int);
typedef int (__thiscall *Fn3)(void *, int);

extern "C" int __cdecl call_495f40(void *);
extern "C" int __cdecl call_983b6a(int);
extern "C" int __stdcall type_info_equal(void *, int);

struct TToolVerb
{
    void *field_0c;
    int f();
};

int TToolVerb::f()
{
    void *p = *(void **)((char *)field_0c + 0xac4);
    int v = call_495f40(p);
    if (!v)
        return 0;
    v = call_983b6a(v);
    return type_info_equal((void *)0xdec154, v);
}

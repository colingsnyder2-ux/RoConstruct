// from server: 66% by atomic.potato
struct TToolVerb
{
    int f();
};

typedef int (*GetVerbType)(void *);
typedef int (*ConvertType)(int);
typedef int (*CompareType)(void *, int);

extern "C" int __cdecl sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int __cdecl sub_b229ec(void *, int);

int TToolVerb::f()
{
    int *p = *(int **)((char *)this + 0xc);
    int type = sub_495f40((void *)p[0xac4 / 4]);
    if (!type)
        return 0;
    return sub_b229ec((void *)0xdec6d0, sub_983b6a(type));
}

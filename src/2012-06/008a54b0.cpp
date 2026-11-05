// from server: 70% by atomic.potato
struct TToolVerb
{
    int f();
};

extern "C" int __cdecl sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int (__cdecl *global_call)(int, int);

int TToolVerb::f()
{
    int value = *(int *)((char *)this + 0x0c);
    value = *(int *)(value + 0x0ac4);
    value = sub_495f40((void *)value);
    if (!value)
        return 0;
    value = sub_983b6a(value);
    return global_call(0x00debdac, value);
}

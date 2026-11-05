// from server: 60% by atomic.potato
typedef unsigned int uint32_t;

struct VTable
{
    void (__thiscall *f)(void *, void *);
};

extern "C" void *__cdecl fn_006c5c20(void *, void *);
extern "C" void *__cdecl fn_004ffee0(void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x20);
    void *value = ((void *(__thiscall *)(void *, void *))(*(void ***)p)[3])(p, arg);
    char storage[8];
    void *holder = storage;
    fn_006c5c20(storage, value);
    return (int)fn_004ffee0((char *)holder + 0x10);
}

// from server: 100% by atomic.potato
typedef int (__cdecl *FactoryFunction)(void *, void *, void *, void *, void *);

extern "C" int __cdecl sub_007f4aaa(void *, void *, void *, void *, void *);

int __stdcall sub_0074f690(void *arg)
{
    int result = sub_007f4aaa(arg, 0, (void *)0xaffe40, (void *)0xb59288, 0);
    return result != 0;
}

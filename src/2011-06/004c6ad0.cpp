// from server: 88% by atomic.potato
typedef int (__cdecl *QueryFunction)(int, int, int, int, const void *, const void *);

extern "C" int __cdecl sub_0080b2ea(int, int, int, int, int, int);

struct EventDesc
{
};

int __cdecl f(int value)
{
    int result = sub_0080b2ea(value, 0, 0, 0xc071f8, 0xc22470, 0);
    return result != 0;
}

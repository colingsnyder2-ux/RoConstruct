// from server: 100% by atomic.potato
struct CXTPDrawHelpers
{
};

extern "C" int __cdecl sub_85c4a0(void *);

int __cdecl f(void *p)
{
    if (p != 0 && sub_85c4a0(*(void **)((char *)p + 4)) != 0)
        return 1;
    return 0;
}

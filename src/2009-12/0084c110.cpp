// from server: 96% by atomic.potato
struct CXTPDrawHelpers
{
    int __cdecl f(void *);
};

extern "C" int __cdecl sub_84a9f0(int);

int __cdecl CXTPDrawHelpers::f(void *p)
{
    if (p && sub_84a9f0(*((int *)p + 1)))
        return 1;
    return 0;
}

// from server: 100% by atomic.potato
struct ForceField
{
    int f(void *);
};

extern "C" int __cdecl sub_80B2EA(void *, void *, int, int, int);

int ForceField::f(void *arg)
{
    return sub_80B2EA(arg, 0, 0xC071F8, 0xC4912C, 0) == 0;
}

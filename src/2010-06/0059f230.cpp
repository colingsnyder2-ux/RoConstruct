// from server: 100% by atomic.potato
struct RBX_Team
{
    int f(void *);
};

extern "C" int __cdecl sub_007A8BEA(void *, int, const char *, const char *, int);

int RBX_Team::f(void *p)
{
    return sub_007A8BEA(p, 0, (const char *)0x00B78E40, (const char *)0x00B9F568, 0) ? 1 : 0;
}

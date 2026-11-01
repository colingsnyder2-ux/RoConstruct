// from server: 100% by atomic.potato
extern "C" int (__cdecl *strcat_s)(char *, unsigned int, const char *);

extern "C" int __cdecl sub_4029f0(int);

int __cdecl sub_44ae70(char *a, unsigned int b, const char *c)
{
    int r = strcat_s(a, b, c);
    return sub_4029f0(r);
}

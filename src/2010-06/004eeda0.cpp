// from server: 100% by atomic.potato
extern "C" int __cdecl sub_4ee5c0(char *, const char *);
extern "C" void __cdecl sub_4e1c10(int, int);

void sub_4eeda0(const char *a)
{
    char b[48];
    char *c = b;
    int d = sub_4ee5c0(c, a);
    sub_4e1c10(*(int *)((char *)&b + 0x38), d);
}

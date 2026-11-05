// from server: 84% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_7265c0(S *, char *, int);

int S::f()
{
    char c;
    int r = sub_7265c0(this, &c, 1);
    if (r == 1)
        return (unsigned char)c;
    return r == -1 ? -1 : -2;
}

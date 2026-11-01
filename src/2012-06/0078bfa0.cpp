// from server: 46% by Intel
struct S
{
    char *field_2c;
    int f(char *p);
};

extern "C" void sub_78b3e0(char *);

int S::f(char *p)
{
    if (p == 0)
        sub_78b3e0(field_2c + ((char *)p - (char *)0x1c));
    else
        sub_78b3e0(field_2c);
    return 0;
}

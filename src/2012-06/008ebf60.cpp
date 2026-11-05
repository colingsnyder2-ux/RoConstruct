// from server: 49% by atomic.potato
struct S
{
    int f(void *p);
    int field_2c;
};

extern "C" int __stdcall sub_7852e0(void *);

int S::f(void *p)
{
    if (p)
        return sub_7852e0((char *)field_2c + (long)p - 0x1c);
    return sub_7852e0((char *)field_2c);
}

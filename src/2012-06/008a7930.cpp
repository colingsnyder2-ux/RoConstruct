// from server: 30% by atomic.potato
extern "C" int sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int sub_b229ec(void *, int);

struct TToolVerb
{
    void *field_0c;
    int f();
};

int TToolVerb::f()
{
    int value = sub_495f40(*(void **)((char *)field_0c + 0xac4));
    if (!value)
        return 0;
    value = sub_983b6a(value);
    return sub_b229ec((void *)0xdecb38, value);
}

// from server: 70% by atomic.potato
extern "C" int __cdecl sub_495f40(void *);
extern "C" void * __cdecl sub_983b6a(int);
extern "C" void *g_b229ec;

struct TToolVerb
{
    char padding[12];
    void *field_0c;
    int f();
};

int TToolVerb::f()
{
    int value = sub_495f40(*(void **)((char *)field_0c + 0xac4));
    if (!value)
        return 0;
    sub_983b6a(value);
    return 0;
}

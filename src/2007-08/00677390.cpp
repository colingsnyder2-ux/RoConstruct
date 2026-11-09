// from server: 100% by colin
struct Inner {
    char pad[0x100];
    int value;
};

struct Outer {
    Inner* method();
};

extern Outer* g_8c86ac;

void func_00677390(int v)
{
    Inner* p = g_8c86ac->method();
    p->value = v;
}

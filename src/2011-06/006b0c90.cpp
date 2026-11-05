// from server: 37% by atomic.potato
struct Sub1 {
    void method(int);
};

struct EventDesc {
    char pad0[4];
    Sub1 sub1;
    int method(int a, int b);
};

struct Sub2 {
    int method(int, int);
};

extern Sub2* g_sub2;

int EventDesc::method(int a, int b)
{
    sub1.method(1);
    return g_sub2->method(a, b);
}

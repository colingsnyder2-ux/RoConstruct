// from server: 100% by colin
struct Sub_00600ad0 {
    void method(int);
};

struct S_0061c1f0 {
    char pad[0x108];
    Sub_00600ad0 sub;
    int m(int arg);
};

int S_0061c1f0::m(int arg)
{
    sub.method(arg);
    return arg;
}

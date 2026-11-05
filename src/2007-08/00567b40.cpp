// from server: 100% by colin
struct S {
    char pad[0x248];
    unsigned char flag;
    void f();
    void g();
};

void S::f()
{
    flag = 1;
    g();
}

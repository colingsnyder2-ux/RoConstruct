// from server: 100% by tester
struct S {
    char pad[0x2b0];
    unsigned char flag;
    void f();
    void g();
};

void S::f()
{
    flag = 1;
    g();
}

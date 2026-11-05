// from server: 90% by atomic.potato
struct S
{
    int a;
    int b;
    int pad[4];
    int c;
    int d;
    void f();
};

void S::f()
{
    a = 0xbb09fc;
    b = 0xbb09f0;
    c = 0xbb09e4;
    d = 0xbb09d8;
}

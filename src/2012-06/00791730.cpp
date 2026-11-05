// from server: 83% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    int d;
    int e;
    int value;
    int g;
    void f();
};

void S::f()
{
    a = 0x00bb23b4;
    b = 0x00bb23ac;
    e = 0x00bb23a0;
    value = 0x00bb2394;
}

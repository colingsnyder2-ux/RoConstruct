// from server: 83% by atomic.potato
struct S
{
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
    a = 0xbb62bc;
    b = 0xbb62b4;
    e = 0xbb62a8;
    value = 0xbb629c;
}

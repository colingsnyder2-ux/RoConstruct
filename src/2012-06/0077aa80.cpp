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
    a = 0xbb07fc;
    b = 0xbb07f4;
    e = 0xbb07e8;
    value = 0xbb07dc;
}

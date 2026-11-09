// from server: 83% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int value_f;
    int g;

    void f();
};

void S::f()
{
    a = 0xbb98ac;
    b = 0xbb98a4;
    e = 0xbb9898;
    value_f = 0xbb988c;
}

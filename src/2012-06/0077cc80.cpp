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
    a = 0xbb0b2c;
    b = 0xbb0b20;
    e = 0xbb0b14;
    value = 0xbb0b08;
}

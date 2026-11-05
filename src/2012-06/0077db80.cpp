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
    a = 0xbb0cf4;
    b = 0xbb0ce8;
    e = 0xbb0cdc;
    value = 0xbb0cd0;
}

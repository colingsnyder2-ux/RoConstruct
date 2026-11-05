// from server: 75% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    void set();
};

void S::set()
{
    a = 0xabcf1c;
    e = 0xabcefc;
}

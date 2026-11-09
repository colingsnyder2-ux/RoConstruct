// from server: 90% by atomic.potato
struct S
{
    int f();
    int a;
    int b;
    int pad[4];
    int c;
    int d;
};

int S::f()
{
    a = 0x00b9da8c;
    b = 0x00b9da80;
    c = 0x00b9da74;
    d = 0x00b9da68;
    return 0;
}

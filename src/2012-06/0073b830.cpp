// from server: 83% by atomic.potato
struct S
{
    void f();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f2;
    int g;
};

S* const p1 = (S*)0x00ba941c;
S* const p2 = (S*)0x00ba9414;
S* const p3 = (S*)0x00ba9408;
S* const p4 = (S*)0x00ba93fc;

void S::f()
{
    a = 0x00ba941c;
    b = 0x00ba9414;
    e = 0x00ba9408;
    f2 = 0x00ba93fc;
}

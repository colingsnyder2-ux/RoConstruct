// from server: 20% by atomic.potato
struct S {
    int value;
    int link1;
    int link2;
    int pad;
    int f();
};

int S::f()
{
    value = 0;
    link1 = (int)&link1;
    link2 = (int)&link1;
    pad = 0;
    return 0;
}

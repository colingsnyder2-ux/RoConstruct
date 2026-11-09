// from server: 29% by atomic.potato
struct S
{
    int f(int);
};

void __stdcall sub_6737d0(S*, int, int);

int S::f(int value)
{
    int flag = 0;
    sub_6737d0(this, value, 0);
    flag |= 1;
    return value;
}

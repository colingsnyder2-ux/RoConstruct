// from server: 28% by atomic.potato
struct S
{
    int f(int value);
};

void sub_004ee3b0(S *, int, int);

int S::f(int value)
{
    int result = 0;
    sub_004ee3b0(this, value, 0);
    result |= 1;
    return value;
}

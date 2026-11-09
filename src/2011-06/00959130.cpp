// from server: 60% by atomic.potato
struct S
{
    int value44;
    int value48;
    int value4c;
    int f(int);
};

extern "C" void sub_958a70(int*, int);

int S::f(int value)
{
    int result = (value4c - value48) >> 5;
    result += value;
    sub_958a70(&value44, result);
    return (value44 + 0 - value48) >> 5;
}

// from server: 91% by atomic.potato
struct S
{
    char padding[0x220];
    float value;
    int f(int, int);
};

extern "C" void __fastcall sub_977d20(int, int, double);

int S::f(int a, int b)
{
    sub_977d20(b, a, (double)value);
    return a;
}

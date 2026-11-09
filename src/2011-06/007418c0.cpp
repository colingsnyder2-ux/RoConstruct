// from server: 58% by atomic.potato
struct S
{
    void (__thiscall *callable)(float, float);
    int value10;
    int value14;
    int value18;

    void f(float a, float b);
};

void S::f(float a, float b)
{
    callable((float)(value10 + value14 + value18), a);
}

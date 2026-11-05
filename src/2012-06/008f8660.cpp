// from server: 57% by atomic.potato
typedef void (__thiscall *Callback)(float, float, float);

struct S
{
    Callback callback;
    int value10;
    int value14;
    int value18;
    void f(float a, float b, float c);
};

void S::f(float a, float b, float c)
{
    callback((float)value10, (float)(value18 + value14), a);
}

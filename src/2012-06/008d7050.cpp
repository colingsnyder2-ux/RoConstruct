// from server: 85% by atomic.potato
struct S
{
    typedef void (__thiscall *Callback)(int, float, float);
    int value;
    int axis;
    Callback callback;
    void f(int, float, float);
};

void S::f(int a, float b, float c)
{
    callback(a, b, c);
}

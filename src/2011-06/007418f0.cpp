// from server: 65% by atomic.potato
struct S
{
    typedef void (__thiscall *Function)(float, int, float);

    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    Function function;

    void f(float, float, float);
};

void S::f(float a, float b, float c)
{
    function(c, value2 + value1, a);
}

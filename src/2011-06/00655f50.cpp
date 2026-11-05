// from server: 71% by atomic.potato
struct S
{
    typedef void (__cdecl *Function)(long long, unsigned long);

    Function function;
    long long value;
    unsigned long argument;

    void f();
};

void S::f()
{
    function(value, argument);
}

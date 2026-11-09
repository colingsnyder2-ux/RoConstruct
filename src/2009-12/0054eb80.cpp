// from server: 41% by atomic.potato
struct S
{
    int f(int value);
};

int S::f(int value)
{
    typedef int (__thiscall *Function)(S *, int);
    Function function = (Function)(*(unsigned char **)*(void ***)this + 0x5c);
    return function(this, value);
}

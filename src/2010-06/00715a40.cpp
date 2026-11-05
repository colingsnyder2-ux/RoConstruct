// from server: 53% by atomic.potato
typedef void (__thiscall *Fn)(void *);
typedef void (__thiscall *FnFloat)(float);

struct S
{
    void *pad0;
    void *pad4;
    void *field10;
    void *field14;
    void f(float value);
};

void S::f(float value)
{
    ((Fn)0x678d40)(field10);
    ((Fn)0x678d40)(field14);
    ((FnFloat)0x1C)(value);
}

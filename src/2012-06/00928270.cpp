// from server: 53% by atomic.potato
struct S
{
    int field0;
    int field1;
    void f(int);
};

extern "C" void __cdecl call1(S *);
extern "C" void __cdecl call2(int *, int);

void __thiscall S::f(int value)
{
    S *self = this;
    int argument = value;
    call1(self);
    call2(&self->field1, argument);
}

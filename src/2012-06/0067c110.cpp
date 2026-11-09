// from server: 50% by atomic.potato
struct S
{
    int f(int);
};

typedef int (__thiscall *CallType)(void *, int);

int S::f(int value)
{
    CallType first = (CallType)0x0067b060;
    CallType second = (CallType)0x0076a190;
    int result = first(this, value + 4);
    int value2 = *(int *)result;
    return second(this, value2);
}

// from server: 68% by atomic.potato
struct S
{
    int f(int);
};

typedef int (__thiscall *GetValueFn)(void *, int);
typedef int (__thiscall *ProcessFn)(void *, int *);

GetValueFn GetValue = 0;
ProcessFn Process = 0;

int S::f(int value)
{
    int result = GetValue(this, value + 4);
    return Process(this, &result);
}

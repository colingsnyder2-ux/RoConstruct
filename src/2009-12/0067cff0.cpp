// from server: 46% by atomic.potato
struct S
{
    int *field0c;
    int field10;

    int f(int value);
};

extern "C" void call_677e50(int *);
extern "C" int call_67bc70(int *, int);
extern "C" int call_63c310(int *, int);

int S::f(int value)
{
    call_677e50(field0c);
    return call_63c310((int *)call_67bc70(&field10, 1), 0);
}

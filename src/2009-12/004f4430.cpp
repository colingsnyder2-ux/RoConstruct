// from server: 21% by atomic.potato
struct S
{
    int f();
};

extern "C" void G1_func_004f4760(int);

int S::f()
{
    int value = 1 ? (int)this : *(int*)this;
    G1_func_004f4760(value);
    return 0;
}

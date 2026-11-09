// from server: 65% by atomic.potato
struct S_func_007fbb90
{
    void f(void** a1, char* a2);
};

void S_func_007fbb90::f(void** a1, char* a2)
{
    if (a2 != 0)
        *a1 = a2 + 0x1c;
    else
        *a1 = 0;
}

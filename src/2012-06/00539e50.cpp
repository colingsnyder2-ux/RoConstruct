// from server: 63% by atomic.potato
struct S
{
    int f(int);
    char pad[44];
    void* p;
};

extern void G1_func_00537040(void*);

int S::f(int value)
{
    if (value != 0)
        G1_func_00537040((char*)p + value - 0x1c);
    else
        G1_func_00537040(p);
    return 0;
}

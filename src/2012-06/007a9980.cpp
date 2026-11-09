// from server: 100% by atomic.potato
extern "C" void __cdecl Call_007a98e0(int, int, int, int);

struct S
{
    int pad[12];
    int field30;
    int field34;
    void f(int*, int*);
};

void S::f(int* a, int* b)
{
    int value = a ? (int)((char*)a - 0x1c) : 0;
    Call_007a98e0(value, field30, field34, (int)((char*)b + 4));
}

// from server: 92% by atomic.potato
struct S
{
    void f(int);
};

extern void G1_func_00893440();
extern void __fastcall G1_func_00805290(S*, int);

void S::f(int value)
{
    if (value == 0x2fbf)
        G1_func_00893440();

    G1_func_00805290(this, value);
}

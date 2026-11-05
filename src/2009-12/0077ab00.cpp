// from server: 52% by atomic.potato
extern "C" void __cdecl sub_778B30(int, void *, int, void *, int);

struct S
{
    int f();
};

int S::f()
{
    int local[6];
    sub_778B30(*(int *)this, this, 0x13, &local[3], 0);
    return (int)this;
}

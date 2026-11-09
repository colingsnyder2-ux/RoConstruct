// from server: 16% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_520BB0(void *, int, int);

int S::f()
{
    int result = 0;
    sub_520BB0(this, result, 0x66);
    return result;
}

// from server: 47% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_7c7640(void*);

int S::f()
{
    sub_7c7640(this);
    return 0;
}

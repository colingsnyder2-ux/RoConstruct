// from server: 60% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_983270(int, int, int, const void*);

void* const g_8AED40 = (void*)0x008AED40;

int S::f()
{
    sub_983270((int)this + 0x38, 0x0C, 5, g_8AED40);
    return 0;
}

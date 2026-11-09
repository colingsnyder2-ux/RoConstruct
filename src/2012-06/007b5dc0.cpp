// from server: 75% by atomic.potato
extern "C" void __cdecl g(int*);

struct S
{
    void f(int);
};

void S::f(int value)
{
    if (*(int*)((char*)this + 0x98) != value)
    {
        *(int*)((char*)this + 0x98) = value;
        g((int*)0x00e4b0c0);
    }
}

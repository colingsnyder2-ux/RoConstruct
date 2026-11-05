// from server: 100% by tester
struct S
{
    int f();
};

int S::f()
{
    return (*(unsigned int*)((char*)this + 0x9c) >> 4) & 1;
}
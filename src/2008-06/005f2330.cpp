// from server: 100% by colin
struct S {
    int f();
};

int S::f()
{
    return (*(unsigned int*)((char*)this + 0x54) >> 4) & 1;
}

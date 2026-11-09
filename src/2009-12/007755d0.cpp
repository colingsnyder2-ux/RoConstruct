// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* a = *(int**)((char*)this + 0x18);
    int b = *(int*)((char*)a + 4);
    int c = *(int*)((char*)a + 0x28);
    return c + b * 6;
}

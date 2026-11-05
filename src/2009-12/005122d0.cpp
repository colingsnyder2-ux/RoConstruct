// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int value = *(int*)((char*)this + 0x16c);
    return value == 0 || value == 2;
}

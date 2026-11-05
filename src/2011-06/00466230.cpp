// from server: 48% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int (*p)(int);
    p = (int (*)(int))(*(int*)((char*)this + 0x20));
    return p(*(int*)((char*)this + 0x24) + *(int*)((char*)this + 0x28));
}

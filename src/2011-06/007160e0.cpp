// from server: 64% by atomic.potato
struct S
{
    int pad0[4];
    int f10;
    int f14;
    int f18;
    int pad1c;
    int f20;

    void f();
};

void S::f()
{
    int* p = *(int**)((char*)this + 0x20);
    int v = *(int*)((char*)this + 0x18);
    int x = *(int*)((char*)p + 0x94);
    x = *(int*)((char*)x + v);
    x += *(int*)((char*)this + 0x14);
    int (*fn)(int) = (int (*)(int))*(int*)((char*)this + 0x10);
    fn((int)((char*)p + x + 0x94));
}

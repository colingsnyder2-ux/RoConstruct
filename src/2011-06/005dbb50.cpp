// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
};

void S::f()
{
    *(int*)((char*)this) = 0xA8FDF4;
    *(int*)((char*)this + 4) = 0xA8FDE8;
    *(int*)((char*)this + 0x18) = 0xA8FDDC;
    *(int*)((char*)this + 0x1C) = 0xA8FDD0;
    g();
}

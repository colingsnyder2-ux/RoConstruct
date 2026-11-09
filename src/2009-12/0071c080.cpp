// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0) = 0x9df774;
    *(int*)((char*)this + 4) = 0x9df768;
    *(int*)((char*)this + 0x18) = 0x9df75c;
    *(int*)((char*)this + 0x1c) = 0x9df754;
    extern void g();
    g();
}

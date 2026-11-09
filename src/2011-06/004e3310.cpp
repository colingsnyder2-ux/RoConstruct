// from server: 88% by atomic.potato
typedef void (*Continuation)();

struct S
{
    void f();
};

void S::f()
{
    *(int*)0x00cb78d4 = 0;
    *(int*)((char*)this + 0x00) = 0x00a79f64;
    *(int*)((char*)this + 0x04) = 0x00a79f58;
    *(int*)((char*)this + 0x18) = 0x00a79f4c;
    *(int*)((char*)this + 0x1c) = 0x00a79f40;
    ((Continuation)0x005980d0)();
}

// from server: 100% by atomic.potato
extern "C" void continuation();

struct S
{
    void f();
};

void S::f()
{
    *(int*)0x00e1a42c = 0;
    *(int*)this = 0x00b8dfbc;
    *(int*)((char*)this + 4) = 0x00b8dfb4;
    *(int*)((char*)this + 0x18) = 0x00b8dfa8;
    *(int*)((char*)this + 0x1c) = 0x00b8df9c;
    continuation();
}

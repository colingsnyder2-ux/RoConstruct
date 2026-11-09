// from server: 90% by atomic.potato
struct S {
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0) = 0xBA5C4C;
    *(int*)((char*)this + 4) = 0xBA5C44;
    *(int*)((char*)this + 0x18) = 0xBA5C38;
    *(int*)((char*)this + 0x1C) = 0xBA5C2C;
}

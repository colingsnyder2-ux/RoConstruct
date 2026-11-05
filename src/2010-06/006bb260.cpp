// from server: 96% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0) = 0x00a42cc4;
    *(int*)((char*)this + 4) = 0x00a42cbc;
    *(int*)((char*)this + 0x18) = 0x00a42cb0;
    *(int*)((char*)this + 0x1c) = 0x00a42ca4;
    *(int*)((char*)this + 0x94) = 0x00a42c94;
    *(int*)((char*)this + 0x98) = 0x00a42c7c;
}

// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0) = 0xbc647c;
    *(int*)((char*)this + 4) = 0xbc6470;
    *(int*)((char*)this + 0x18) = 0xbc6464;
    *(int*)((char*)this + 0x1c) = 0xbc6458;
    *(int*)((char*)this + 0x80) = 0xbc642c;
}

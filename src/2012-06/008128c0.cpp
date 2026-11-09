// from server: 82% by atomic.potato
extern "C" void target_811a80(void*);

struct S
{
    void f();
};

void S::f()
{
    *(unsigned long*)((char*)this + 0x00) = 0x00bc6854UL;
    *(unsigned long*)((char*)this + 0x04) = 0x00bc684cUL;
    *(unsigned long*)((char*)this + 0x18) = 0x00bc6840UL;
    *(unsigned long*)((char*)this + 0x1c) = 0x00bc6834UL;
    *(unsigned long*)((char*)this + 0x80) = 0x00bc6808UL;
    target_811a80(this);
}

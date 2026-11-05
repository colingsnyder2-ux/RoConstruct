// from server: 26% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    float v = *(float*)0xa0c610;
    *(int*)((char*)this + 0) = 0;
    *(char*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(float*)((char*)this + 0x10) = v;
    *(float*)((char*)this + 0x14) = v;
    *(float*)((char*)this + 0x18) = v;
    *(float*)((char*)this + 0x1c) = v;
    *(int*)((char*)this + 0xc) = 2;
    *(float*)((char*)this + 0x20) = 0.0f;
    *(float*)((char*)this + 0x24) = 0.0f;
    *(float*)((char*)this + 0x28) = 0.0f;
}

// from server: 100% by atomic.potato
struct S
{
    void f(const float* p);
};

void S::f(const float* p)
{
    *(float*)((char*)this + 0x20) = p[0];
    *(float*)((char*)this + 0x24) = p[1];
    *(float*)((char*)this + 0x28) = p[2];
}

// from server: 87% by atomic.potato
extern "C" void call_008f92c0(
    void* object, float a, float b, float c);

struct S
{
    void f(float a, float b, float c);
};

void S::f(float a, float b, float c)
{
    call_008f92c0((char*)this + 0x10, c, b, a);
}

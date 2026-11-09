// from server: 85% by atomic.potato
struct S_008f8c10 {
    void f(float, float, float, float);
};

extern "C" void call_008f8b60(void*, float, float, float, float);

void S_008f8c10::f(float a, float b, float c, float d)
{
    call_008f8b60((char*)this + 16, d, c, b, a);
}

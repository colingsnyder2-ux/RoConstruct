// from server: 77% by atomic.potato
struct Climbing {
    void* vtable;
    int field4;
    int field8;
    float fieldC;
    void* init(int, int);
};

extern "C" void __stdcall sub_007ec080(int, int);

void* Climbing::init(int a, int b)
{
    sub_007ec080(a, b);
    fieldC = *(float*)0xaabd58;
    vtable = (void*)0xabcad0;
    field4 = 0xabcac4;

    return this;
}

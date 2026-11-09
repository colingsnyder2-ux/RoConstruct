// from server: 100% by atomic.potato
extern "C" void __stdcall UpdateKeyframeSequence(unsigned long);

struct S
{
    unsigned char padding[0xd0];
    unsigned long value;
    void f(unsigned long);
};

void S::f(unsigned long value)
{
    if (this->value != value)
    {
        this->value = value;
        UpdateKeyframeSequence(0x00e4a8d8);
    }
}

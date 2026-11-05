// from server: 77% by atomic.potato
extern "C" void __cdecl sub_411f60(int);

struct RefPropDescriptor
{
    int padding[40];
    int value;
    void f(int*);
};

void RefPropDescriptor::f(int* value)
{
    int v = *value;
    if (v != this->value)
    {
        this->value = v;
        sub_411f60(0x00cb7bf8);
    }
}

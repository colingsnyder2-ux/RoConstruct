// from server: 100% by atomic.potato
extern "C" void __stdcall Function_0040C080(int);

struct FactoryProduct_00748D10
{
    char pad0[444];
    int value;
    void set(int);
};

void FactoryProduct_00748D10::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        Function_0040C080(0x00B96F3C);
    }
}

// from server: 100% by atomic.potato
struct S
{
    int padding[116];
    int value;
    void set(int);
};

extern "C" void __stdcall UpdateValue(int);

void S::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        UpdateValue(0x00B976C4);
    }
}

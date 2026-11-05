// from server: 87% by atomic.potato
extern "C" void __cdecl notify(int);

struct S
{
    char padding[0x174];
    int value;
    void set(int);
};

void S::set(int value)
{
    if (value < 0)
        value = 0;
    else if (value > 1)
        value = 1;

    if (this->value != value)
    {
        this->value = value;
        notify(value);
    }
}

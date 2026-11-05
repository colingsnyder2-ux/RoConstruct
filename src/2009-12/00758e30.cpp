// from server: 100% by atomic.potato
extern "C" void __stdcall Call_0040C080(int);

struct S
{
    char padding[0x2F4];
    int value;
    void Set(int);
};

void S::Set(int value)
{
    if (this->value == value)
        return;

    this->value = value;
    Call_0040C080(0x00B975C8);
}

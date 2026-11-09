// from server: 100% by atomic.potato
struct S {
    char padding[0xbc];
    int value;
    void set(int);
};

extern "C" void __stdcall G1_func_0040c080(int);

void S::set(int value)
{
    if (value != this->value) {
        this->value = value;
        G1_func_0040c080(0x00b7b0b0);
    }
}

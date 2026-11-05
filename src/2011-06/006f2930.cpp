// from server: 80% by atomic.potato
struct S_func_006f2930 {
    char pad0[60];
    void f(unsigned int index, unsigned char value);
};

void S_func_006f2930::f(unsigned int index, unsigned char value)
{
    if (index < 0x200)
        pad0[index] = value;
}

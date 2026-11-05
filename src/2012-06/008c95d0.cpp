// from server: 80% by atomic.potato
struct S_func_008c95d0 {
    char pad[129];
    unsigned char value;
    void f(unsigned char value);
};

void S_func_008c95d0::f(unsigned char value)
{
    if (this->value != value) {
        this->value = value;
        *(unsigned long*)0x00000004 = 0x00e53a04;
    }
}

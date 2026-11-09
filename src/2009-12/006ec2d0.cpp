// from server: 87% by atomic.potato
struct S
{
    unsigned char padding[0x80];
    unsigned char state;
    unsigned char padding2[0x77];
    void *object;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != state)
    {
        state = value;
        void **vtable = (void **)object;
        typedef void (__thiscall *Function)(void *);
        ((Function)vtable[3])(object);
    }
}

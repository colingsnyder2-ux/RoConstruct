// from server: 83% by atomic.potato
struct S
{
    int f(unsigned char value);
};

extern "C" void __cdecl Function_40C080();

int S::f(unsigned char value)
{
    if (*((unsigned char *)this + 0x1cc) != value)
    {
        *((unsigned char *)this + 0x1cc) = value;
        Function_40C080();
    }
    return 0;
}

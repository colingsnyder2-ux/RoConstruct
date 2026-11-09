// from server: 73% by atomic.potato
struct S
{
    void f(unsigned short* result, const unsigned short* value);
};

void __thiscall S::f(unsigned short* result, const unsigned short* value)
{
    result[0] = (unsigned short)(*(unsigned short*)this - value[0]);
    result[1] = (unsigned short)(*((unsigned short*)this + 1) - value[1]);
    result[2] = (unsigned short)(*((unsigned short*)this + 2) - value[2]);
}

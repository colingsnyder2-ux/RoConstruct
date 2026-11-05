// from server: 71% by atomic.potato
struct S
{
    void f(unsigned short* out, const unsigned short* value);
};

void __declspec(nothrow) __thiscall S::f(unsigned short* out, const unsigned short* value)
{
    out[0] = (unsigned short)(value[0] + *(unsigned short*)((char*)this));
    out[1] = (unsigned short)(value[1] + *(unsigned short*)((char*)this + 2));
    out[2] = (unsigned short)(value[2] + *(unsigned short*)((char*)this + 4));
}

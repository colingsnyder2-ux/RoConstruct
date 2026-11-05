// from server: 72% by atomic.potato
extern "C" void __stdcall Call9651f0(void*);

struct S
{
    void __thiscall f(int);
};

void __thiscall S::f(int value)
{
    value -= 2;
    if (value == 0)
    {
        Call9651f0(this);
        return;
    }

    value -= 3;
    if (value != 0)
        return;

    void** table = *(void***)((char*)this + 0x1c4);
    typedef void (__thiscall *Fn)(void*);
    ((Fn)table[0])((char*)this + 0x1c4);
}

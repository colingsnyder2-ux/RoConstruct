// from server: 81% by atomic.potato
typedef short (__stdcall *GetKeyStateType)(int);

extern "C" short __stdcall GetKeyState(int);
extern "C" void Function007f3e30(void *);

struct S
{
    virtual void Function0();
};

void S::Function0()
{
    short state = GetKeyState(0x11);
    if (state >= 0)
    {
        typedef void (__thiscall *FunctionType)(S *, int);
        FunctionType function = (FunctionType)(*(unsigned long *)((char *)*(unsigned long **)this + 0x94));
        function(this, 1);
    }
    Function007f3e30(this);
}

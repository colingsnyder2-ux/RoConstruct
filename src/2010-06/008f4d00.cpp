// from server: 77% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    void Call(DWORD);
};

void S::Call(DWORD value)
{
}

extern "C" void __stdcall Function008F4AB0(S* object, DWORD value);

extern "C" void Function008F4D00(DWORD unused, DWORD count, S* object, DWORD value)
{
    if (count == 0)
        return;

    do
    {
        if (object != 0)
            Function008F4AB0(object, value);

        --count;
        object = (S*)((char*)object + 0x48);
    }
    while (count != 0);
}

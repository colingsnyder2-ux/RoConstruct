// from server: 100% by colin
struct S
{
    void f(int);
};

void S::f(int arg)
{
    if (arg == 1)
    {
        if ((*(unsigned char*)((char*)this + 0xb0) & 2) == 0)
        {
            *(int*)(*(int*)((char*)this + 0x10)) = 0;
            *(int*)(*(int*)((char*)this + 0x20)) = 0;
            *(int*)(*(int*)((char*)this + 0x30)) = 0;
            *(unsigned int*)((char*)this + 0xb0) |= 2;
        }
    }
    else if (arg == 2)
    {
        if ((*(unsigned char*)((char*)this + 0xb0) & 4) == 0)
        {
            (*(void(**)(void))(*(int*)this + 0x30))();
            *(int*)(*(int*)((char*)this + 0x14)) = 0;
            *(int*)(*(int*)((char*)this + 0x24)) = 0;
            *(int*)(*(int*)((char*)this + 0x34)) = 0;
            *(unsigned int*)((char*)this + 0xb0) |= 4;
        }
    }
}

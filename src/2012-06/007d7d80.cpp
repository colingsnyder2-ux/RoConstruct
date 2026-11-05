// from server: 60% by atomic.potato
struct S
{
};

void __cdecl f(int, int value, int out)
{
    if (out != 4)
        return;

    *(unsigned long*)value = 0x00dcf7b8;
    ((unsigned char*)value)[4] = 0;
    ((unsigned char*)value)[5] = 0;
}

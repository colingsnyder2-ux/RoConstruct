// from server: 100% by atomic.potato
extern "C" void __cdecl sub_6c9890(int, int, int);

void EventDesc(int a, int b, int c)
{
    if (c != 4)
    {
        sub_6c9890(a, b, c);
    }
    else
    {
        *(unsigned long*)b = 0x00bd2498;
        *(unsigned char*)(b + 4) = 0;
        *(unsigned char*)(b + 5) = 0;
    }
}

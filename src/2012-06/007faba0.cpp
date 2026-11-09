// from server: 54% by atomic.potato
extern "C" void __cdecl Function9831F5(const char*);

unsigned char& GlobalB0 = *(unsigned char*)0x00e4f4b0;
unsigned long& GlobalA8 = *(unsigned long*)0x00e4f4a8;
unsigned long& GlobalAC = *(unsigned long*)0x00e4f4ac;

void Function7FABA0()
{
    if (GlobalB0 == 0)
    {
        GlobalB0 |= 1;
        GlobalA8 = 0;
        GlobalAC = 0;
        Function9831F5((const char*)0x00b1dbc0);
    }
}

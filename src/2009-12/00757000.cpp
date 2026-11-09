// from server: 100% by atomic.potato
extern "C" void __stdcall Function40C080(int);

void __stdcall Function757000(int value)
{
    if (value == 0x00B97AC0)
    {
        value = 0x00B97448;
        Function40C080(value);
    }
    else if (value == 0x00B97AE0)
    {
        value = 0x00B97468;
        Function40C080(value);
    }
}

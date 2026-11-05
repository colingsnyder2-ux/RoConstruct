// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5cdb20();
extern "C" void __cdecl sub_5cdc80();

void __stdcall f(unsigned int a)
{
    if (a == 0xb946bc)
    {
        sub_5cdb20();
        return;
    }
    if (a == 0xb920dc || a == 0xb920bc || a == 0xb920fc)
    {
        sub_5cdc80();
    }
}

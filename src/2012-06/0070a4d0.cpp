// from server: 24% by atomic.potato
extern "C" void __stdcall sub_00709be0();
extern "C" void __stdcall sub_009831f5();

void func_0070a4d0()
{
    if ((*(unsigned char*)0xe31328 & 1) == 0)
    {
        *(unsigned int*)0xe31328 |= 1;
        sub_00709be0();
        *(unsigned int*)0xe3130c = 0xb9fb84;
        sub_009831f5();
    }
}

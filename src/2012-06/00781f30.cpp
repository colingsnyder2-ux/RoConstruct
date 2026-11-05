// from server: 23% by atomic.potato
extern "C" void __stdcall func_004125d0();
extern "C" void __stdcall func_006cab60();
extern "C" void __stdcall func_009831f5();

void func_00781f30()
{
    if ((*(unsigned char*)0xe4469c & 1) == 0)
    {
        *(unsigned int*)0xe4469c |= 1;
        char buf[12];
        buf[0] = 0;
        buf[1] = 0;
        *(unsigned int*)(buf + 4) = 0;
        *(unsigned int*)(buf + 8) = 0x1b;
        func_004125d0();
        func_006cab60();
        func_009831f5();
    }
}

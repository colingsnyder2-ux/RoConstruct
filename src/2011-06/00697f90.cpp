// from server: 70% by atomic.potato
extern "C" void __cdecl Function0080B15D(int);

int Function00697F90()
{
    *(unsigned char*)0x00CCFA70 += 0;
    Function0080B15D(*(int*)0x00CCFA70);
    return *(int*)0x00CCFA6C;
}

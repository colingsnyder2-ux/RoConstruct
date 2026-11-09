// from server: 65% by atomic.potato
struct StarterGuiService
{
    void f();
    unsigned char pad[0xA2];
};

void StarterGuiService::f()
{
    if (pad[0xA1] != 0)
        ((void (__thiscall *)(void *))0x58A980)((void *)*(void **)(pad + 0x98));
}

// from server: 33% by Intel
extern "C" void __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_9831f5(int);

int sub_55AFE0()
{
    sub_4015a0(0x55AFB0, 0xE23C78);
    if (*(unsigned char*)0xE23C74)
        return 0xE23C6C;

    *(unsigned char*)0xE23C74 = 1;
    *(int*)0xE23C6C = 0;
    *(int*)0xE23C70 = 0;
    sub_9831f5(0xB142B0);
    return 0xE23C6C;
}

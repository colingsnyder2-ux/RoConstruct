// from server: 33% by Intel
extern "C" int __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_9831f5(int);

int sub_6D34F0()
{
    sub_4015a0(0x6D20F0, 0xE2F970);
    if (!*reinterpret_cast<unsigned char*>(0xE2F92C))
    {
        *reinterpret_cast<unsigned char*>(0xE2F92C) = 1;
        *reinterpret_cast<int*>(0xE2F924) = 0;
        *reinterpret_cast<int*>(0xE2F928) = 0;
        sub_9831f5(0xB16A70);
    }
    return 0xE2F924;
}

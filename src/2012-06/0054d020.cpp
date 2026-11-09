// from server: 81% by Intel
typedef unsigned int DWORD;
typedef unsigned char BYTE;

extern "C" void __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_9831f5(int);

DWORD dword_E21D68;
DWORD dword_E21D6C;
BYTE byte_E21D70;

int __cdecl sub_54D020()
{
    sub_4015a0(0x54CFF0, 0xE21D74);

    if (byte_E21D70 & 1)
    {
        return (int)&dword_E21D68;
    }

    byte_E21D70 |= 1;
    dword_E21D68 = 0;
    dword_E21D6C = 0;
    sub_9831f5(0xB13860);

    return (int)&dword_E21D68;
}

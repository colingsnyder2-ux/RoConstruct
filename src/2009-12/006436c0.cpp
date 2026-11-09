// from server: 32% by atomic.potato
extern unsigned char G1;
extern unsigned char G2;
extern unsigned char G3;
extern unsigned char G4;

extern "C" int __stdcall sub_00642540(int, int);
extern "C" int __stdcall sub_007F4929(int);

int f_006436c0()
{
    if (!(G1 & 1))
    {
        G1 |= 1;
        sub_00642540(0x9cca28, 0);
        G2 = 0;
        sub_007F4929(0x981ee0);
    }
    return 0xb85d78;
}

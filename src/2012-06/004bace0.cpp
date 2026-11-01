// from server: 100% by Intel
unsigned long dword_E1C22C;
unsigned long dword_E1C230;
unsigned long dword_E1C234;

extern "C" void __cdecl sub_4015A0(unsigned long, unsigned long);
extern "C" void __cdecl sub_9831F5(unsigned long);

unsigned long sub_4BACE0() {
    sub_4015A0(0x4BA680, 0xE1C250);
    if (dword_E1C234 & 1) {
        return 0xE1C22C;
    }
    dword_E1C234 |= 1;
    dword_E1C22C = 0;
    dword_E1C230 = 0;
    sub_9831F5(0xB129A0);
    return 0xE1C22C;
}

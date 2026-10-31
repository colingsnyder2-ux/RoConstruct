// from server: 65% by Intel
extern "C" void __stdcall __security_init_cookie(int, int);
extern "C" void __cdecl sub_9831F5(int);

struct islot {
    static int instance();
};

int islot::instance() {
    __security_init_cookie(0x428850, 0xE1828C);
    if (!*(unsigned char*)0xE18284) {
        *(unsigned char*)0xE18284 = 1;
        *(int*)0xE1827C = 0;
        *(int*)0xE18280 = 0;
        sub_9831F5(0xB118A0);
    }
    return 0xE1827C;
}

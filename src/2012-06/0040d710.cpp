// from server: 94% by Intel
extern "C" int __cdecl sub_972290(int, const char*);
extern "C" void __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_40bc40();
extern "C" void __cdecl sub_67f480();

int __cdecl sub_40d710() {
    if (*(char*)0xe580b3) {
        if (*(int*)0xe16528 != 0x29a) {
            int (__cdecl* callback)(int, int, int) = (int (__cdecl*)(int, int, int))*(int*)0xe5809c;
            if (callback) {
                if (callback(0xb42f90, 0xb42fa8, 0xcf)) {
                    return 0;
                }
            }
            sub_972290(*(char*)0xe580b3, (const char*)0xb42f20);
        }
    }
    if (!*(int*)0xb57664) {
        sub_67f480();
    }
    sub_4015a0(0xe16570, 0x40c9b0);
    sub_40bc40();
    return 0;
}

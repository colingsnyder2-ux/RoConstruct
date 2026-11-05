// from server: 72% by atomic.potato
extern "C" int __cdecl sub_80B2EA(int, int, int, int, int);
extern "C" void __cdecl sub_80B0AC(int, int);
extern "C" void __cdecl sub_6219C0(int, int, int, int);
extern "C" void __cdecl sub_A40A10(int);

struct RBX_VDebugSettings {
    char pad[0x28];
    int field28;
    int field2C;
    void func(int, int);
};

void RBX_VDebugSettings::func(int a, int b)
{
    int result = sub_80B2EA(a, 0, 0xC35888, 0xC073F8, 0);
    if (result == 0) {
        sub_A40A10(0xA5C10C);
        sub_80B0AC(0xB989FC, (int)&result);
    }
    sub_6219C0(result, field28, field2C, b + 4);
}

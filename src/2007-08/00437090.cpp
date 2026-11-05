// from server: 33% by Intel
struct Listener {
    int __cdecl func(int a1, int a2);
};

extern "C" int __cdecl swprintf_s(wchar_t*, unsigned int, const wchar_t*, ...);
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" int __cdecl sub_4016e0(int);

int Listener::func(int a1, int a2) {
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;
    int cookie = *(int*)0x8B5188 ^ (int)&v3;
    v4 = a1;
    v5 = a2;
    v6 = 0;
    swprintf_s((wchar_t*)&v6, 11, (const wchar_t*)0x78CDB0, v4);
    v7 = 0;
    memcpy_s(&v7, 20, &v6, 22);
    return sub_4016e0(v7);
}

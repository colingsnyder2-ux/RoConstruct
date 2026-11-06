// from server: 62% by Intel
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int errno_t;

extern "C" errno_t __stdcall memcpy_s(void* dest, size_t destSize, const void* src, size_t count);
extern "C" int __stdcall swprintf_s(wchar_t* buffer, size_t sizeOfBuffer, const wchar_t* format, ...);
extern "C" int __cdecl sub_4016e0(int);

struct Listener {
    int func(int a1, int a2);
};

int Listener::func(int a1, int a2) {
    int v3 = a1;
    int v4 = a2;
    wchar_t dest[11];
    wchar_t buffer[10];

    memcpy_s(dest, 22, (void*)0x78CDB0, 11);
    swprintf_s(buffer, 10, L"%d", v3);
    int result = sub_4016e0(v4);
    return result;
}

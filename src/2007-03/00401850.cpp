// from server: 100% by tester
extern "C" int (__stdcall *lstrlenW)(const wchar_t*);
extern "C" int (__cdecl *memcpy_s)(void*, unsigned int, const void*, unsigned int);

int __cdecl sub_00401840(int a1, int a2, const wchar_t* a3)
{
    int len = lstrlenW(a3);
    int result = memcpy_s((void*)a1, (unsigned int)(a2 * 2), a3, (unsigned int)(len * 2 + 2));
    return result == 0;
}

// from server: 100% by tester
extern "C" void* (__cdecl *memcpy_s_import)(void*, unsigned int, const void*, unsigned int);
extern "C" void* __cdecl sub_4016E0(void*);

void* __cdecl sub_401880(void* dst, unsigned int size, const void* src, unsigned int count)
{
    void* p = memcpy_s_import(dst, size, src, count);
    return sub_4016E0(p);
}

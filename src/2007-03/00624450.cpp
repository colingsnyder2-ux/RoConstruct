// from server: 100% by tester
extern "C" int (__cdecl *memcpy_s)(void *dest, unsigned int destSize, const void *src, unsigned int count);

void sub_00647a90(int dest, int destSize, int src)
{
    memcpy_s((void *)dest, (unsigned int)src, (const void *)destSize, (unsigned int)src);
}

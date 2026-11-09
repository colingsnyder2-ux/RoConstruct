// from server: 100% by tester
extern "C" void* (__cdecl *malloc_ptr)(unsigned int);

void* __cdecl sub_0051EB90(int flag, unsigned int size)
{
    if (flag != 0 && size != 0)
        return malloc_ptr(size);
    return 0;
}

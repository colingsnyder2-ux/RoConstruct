// from server: 100% by colin
extern "C" void* (__cdecl *malloc_ptr)(unsigned int);

void* __cdecl sub_007223e0(unsigned int a, unsigned int b, unsigned int c)
{
    return malloc_ptr(b * c);
}

// from server: 100% by tester
extern "C" void* (__cdecl *malloc_ptr)(unsigned int);

void* f(int unused, unsigned int size)
{
    return malloc_ptr(size);
}

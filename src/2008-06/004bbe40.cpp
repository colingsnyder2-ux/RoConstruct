// from server: 100% by tester
extern "C" void* (__cdecl* malloc_ptr)(unsigned int);

void* __stdcall sub_4b90c0(unsigned int size)
{
    char* p = (char*)malloc_ptr(size + 0x1c);
    *(unsigned int*)(p + 0xc) = size;
    *(char**)(p + 0x14) = p + 0x1c;
    *(char*)(p + 0x18) = 0;
    return p;
}

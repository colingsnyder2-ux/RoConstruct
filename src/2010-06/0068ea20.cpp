// from server: 87% by atomic.potato
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl _invalid_parameter_noinfo();

void* __cdecl AllocateOrThrow(unsigned int size)
{
    void* result;
    unsigned int adjusted = size;
    if (size <= 0)
        adjusted = 1;
    result = malloc(adjusted);
    if (result == 0 && size != 0)
    {
        if (*(volatile char*)0x00bc48f8 == 0)
            _invalid_parameter_noinfo();
    }
    return result;
}

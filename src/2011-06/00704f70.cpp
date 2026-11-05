// from server: 50% by atomic.potato
extern "C" void __cdecl func_00401610();
extern "C" void __cdecl func_0080b15d();

void* func_00704f70()
{
    func_00401610();
    if ((*(unsigned char*)0xcd2f18 & 1) == 0)
    {
        *(unsigned int*)0xcd2f18 |= 1;
        *(unsigned int*)0xcd2f10 = 0;
        *(unsigned int*)0xcd2f14 = 0;
        func_0080b15d();
    }
    return (void*)0xcd2f10;
}

// from server: 57% by colin
extern "C" void __cdecl func_009831f5();

void func_006d1a50()
{
    int one = 1;
    if ((*(unsigned char*)0xe2f914 & one) != 0)
        return;
    *(unsigned int*)0xe2f914 |= one;
    *(unsigned int*)0xe2f90c = 0;
    *(unsigned int*)0xe2f910 = 0;
    func_009831f5();
}

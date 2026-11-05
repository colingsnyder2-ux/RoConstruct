// from server: 100% by atomic.potato
extern "C" void func_0045f5c0(int, int*, int);

void func_0045ff90(int a, int* p, int b)
{
    if (b != 4)
    {
        func_0045f5c0(a, p, b);
        return;
    }
    *p = 0x00b0a380;
    ((char*)p)[4] = 0;
    ((char*)p)[5] = 0;
}

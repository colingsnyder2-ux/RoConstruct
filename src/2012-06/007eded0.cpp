// from server: 100% by atomic.potato
extern "C" void __cdecl target(void*, void*, int);

void f(void* a, void* b, int c)
{
    if (c != 4)
    {
        target(a, b, c);
    }
    else
    {
        *(unsigned long*)b = 0x00dd4418;
        *((unsigned char*)b + 4) = 0;
        *((unsigned char*)b + 5) = 0;
    }
}

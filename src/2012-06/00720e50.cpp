// from server: 58% by atomic.potato
extern "C" void placeholder();

void f(int a, int* p)
{
    if (a != 4)
        placeholder();
    else
    {
        *p = 0x00DADF40;
        *((unsigned char*)p + 4) = 0;
        *((unsigned char*)p + 5) = 0;
    }
}

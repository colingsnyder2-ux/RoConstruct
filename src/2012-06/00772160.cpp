// from server: 52% by atomic.potato
typedef void (__cdecl *FunctionType)();

extern "C" void __cdecl FunctionAt9831F5();

volatile unsigned char& flag = *(volatile unsigned char*)0xE39AB4;
volatile unsigned long& globalA = *(volatile unsigned long*)0xE39AAC;
volatile unsigned long& globalB = *(volatile unsigned long*)0xE39AB0;

void FunctionAt772160()
{
    if (flag & 1)
        return;

    flag |= 1;
    globalA = 0;
    globalB = 0;
    FunctionAt9831F5();
}

// from server: 52% by atomic.potato
typedef void (*FunctionType)();

volatile unsigned char& g_initialized = *(volatile unsigned char*)0x00e4f48c;
volatile unsigned long& g_value1 = *(volatile unsigned long*)0x00e4f484;
volatile unsigned long& g_value2 = *(volatile unsigned long*)0x00e4f488;

void FunctionTypeCall();
FunctionType g_function = (FunctionType)0x009831f5;

void FunctionTypeCall()
{
    g_function();
}

void f()
{
    if (g_initialized & 1)
        return;

    g_initialized |= 1;
    g_value1 = 0;
    g_value2 = 0;
    g_function();
}

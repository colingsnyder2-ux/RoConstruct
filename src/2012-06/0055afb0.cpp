// from server: 79% by atomic.potato
typedef void (*FunctionType)();

volatile unsigned char g_flag;
volatile unsigned long g_value1;
volatile unsigned long g_value2;

FunctionType g_function = (FunctionType)0x00b142b0;

void Function_0055afb0()
{
    if (!g_flag)
    {
        g_flag = 1;
        g_value1 = 0;
        g_value2 = 0;
        g_function();
    }
}

// from server: 80% by atomic.potato
typedef void (__cdecl FunctionType)();

extern "C" FunctionType g_function;
extern "C" int g_initialized;
extern "C" int g_value1;
extern "C" int g_value2;
extern "C" const char g_name[];

void Function()
{
    if (!(g_initialized & 1))
    {
        g_initialized |= 1;
        g_value1 = 0;
        g_value2 = 0;
        g_function();
    }
}

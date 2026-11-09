// from server: 99% by atomic.potato
typedef void (*InitFunction)();

int g_flag;
int g_value1;
int g_value2;
const char g_name[] = "8csm";

extern "C" void InitFunctionCall(const char*);

void Function0069af50()
{
    if (g_flag & 1)
        return;

    g_flag |= 1;
    g_value1 = 0;
    g_value2 = 0;
    InitFunctionCall(g_name);
}

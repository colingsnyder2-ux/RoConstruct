// from server: 100% by atomic.potato
extern "C" int __cdecl UniversalTool(int, int, int);

int g_value;

int Function(int a, int b)
{
    return UniversalTool(a, b, g_value);
}

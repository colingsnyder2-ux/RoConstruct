// from server: 100% by atomic.potato
extern "C" int __cdecl UniversalToolCall(int, int, int);

extern int g_value;

int Function(int a, int b)
{
    int result = UniversalToolCall(a, b, 0);
    if (result == 0)
        result = g_value;
    return result;
}

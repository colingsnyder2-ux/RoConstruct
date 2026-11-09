// from server: 100% by atomic.potato
extern "C" int * __cdecl CallPrimitive(int, int, int);
extern "C" void __cdecl ReleaseObject(int);

int g_value;

int Function(int value)
{
    int result = *CallPrimitive(value, 1, g_value);
    if (result)
        ReleaseObject(result);
    return 0;
}

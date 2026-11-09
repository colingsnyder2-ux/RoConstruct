// from server: 53% by atomic.potato
extern "C" int __cdecl Function53F4A0(int);
extern "C" int __cdecl Function533330(int, int, int*);

int Function40860(int a, int b, int c, int d)
{
    int result;
    int value = Function53F4A0(a);
    Function533330(d, value, &result);
    return result;
}

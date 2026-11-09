// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7e5b60(int);
extern "C" int __cdecl sub_7e5d40(int);

extern int g_00b64ae8;

int f(int value)
{
    if (g_00b64ae8 <= 1)
        sub_7e5b60(value);
    else
        sub_7e5d40(value);
    return value;
}

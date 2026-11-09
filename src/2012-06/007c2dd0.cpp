// from server: 48% by atomic.potato
typedef unsigned char BYTE;

extern BYTE g_00e31abe;

struct S
{
    int f();
    int value;
};

int S::f()
{
    if (g_00e31abe)
        return 1;
    return value;
}

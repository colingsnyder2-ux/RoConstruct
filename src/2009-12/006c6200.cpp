// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern BYTE g_b99b84;
extern BYTE g_b33018;
extern const char g_b9241c[];

extern "C" void __stdcall Dispatch(const char *);

void __stdcall Function006c6200(BYTE value)
{
    BYTE v = 1;
    if (g_b99b84 != 0)
        v = value;

    if (v == g_b33018)
        return;

    g_b33018 = v;
    Dispatch(g_b9241c);
}

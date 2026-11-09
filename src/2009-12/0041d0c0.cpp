// from server: 63% by atomic.potato
typedef unsigned short WORD;
typedef void *HMENU;
typedef void *HINSTANCE;

extern "C" HMENU __stdcall LoadMenuA(HINSTANCE, const char *);

struct CSettingsExplorer
{
    void f(WORD);
};

extern "C" HMENU sub_007f41de(int, int, WORD);
extern "C" void sub_007f41d8(CSettingsExplorer *, HMENU);

void CSettingsExplorer::f(WORD value)
{
    HMENU menu = (HMENU)sub_007f41de(value, 4, value);
    menu = LoadMenuA(menu, (const char *)menu);
    sub_007f41d8(this, menu);
}

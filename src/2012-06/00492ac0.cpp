// from server: 87% by atomic.potato
extern "C" void __cdecl CallToggle(int, const char *, int);
extern "C" void CallView(void *);

extern unsigned char g_toggleViewMode;
extern const char g_toggleViewModeName[];

struct ToggleViewMode
{
    void Toggle();
    void *field0c;
};

void ToggleViewMode::Toggle()
{
    if (g_toggleViewMode)
        CallToggle((int)g_toggleViewMode, g_toggleViewModeName, 0);
    CallView(field0c);
}

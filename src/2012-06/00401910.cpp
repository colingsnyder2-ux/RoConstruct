// from server: 100% by tajop
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
extern "C" void __cdecl func_009831f5(void*);

struct CAboutRobloxDialog
{
    static CAboutRobloxDialog* GetInstance();
};

CAboutRobloxDialog* CAboutRobloxDialog::GetInstance()
{
    static int initFlag;
    static char section[24];
    static int field24;
    static int field28;
    static int field2c;
    static int field30;
    static int field34;
    static int field38;

    if ((initFlag & 1) == 0)
    {
        initFlag |= 1;
        InitializeCriticalSection(section);
        field24 = 0;
        field28 = 0;
        field2c = 0;
        field30 = 0x18;
        field34 = 0x20;
        field38 = 0x20;
        func_009831f5((void*)0xb11390);
    }
    return (CAboutRobloxDialog*)section;
}

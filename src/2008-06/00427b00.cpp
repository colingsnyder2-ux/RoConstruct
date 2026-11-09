// from server: 100% by king_originala
extern bool initialShown;
extern "C" int __stdcall reportCrash(void *);
extern "C" int (__stdcall *MessageBoxA)(void *, const char *, const char *, unsigned int);

int __stdcall crashHandler(void *argument)
{
    int result = reportCrash(argument);
    static bool shown = initialShown;
    if (!shown)
    {
        shown = true;
        MessageBoxA(0,
            "An unexpected error occurred and ROBLOX needs to quit.  We're sorry!",
            "ROBLOX Crash", 0);
    }
    return result;
}

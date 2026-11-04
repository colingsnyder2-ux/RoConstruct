// from server: 97% by Intel
extern unsigned char g_GlobalFlag;
extern const char g_GlobalString[];

extern "C" void __cdecl CallbackFunction(int, const char*, int);
extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct WindowContainer {
    char padding[0x20];
    void* windowHandle;
};

struct InsertModelFromRobloxVerb {
    char padding[0xC];
    WindowContainer* container;
    void Method(int arg);
};

void InsertModelFromRobloxVerb::Method(int arg)
{
    if (g_GlobalFlag) {
        CallbackFunction(g_GlobalFlag, g_GlobalString, 0);
    }
    WindowContainer* container = this->container;
    void* hwnd = container->windowHandle;
    PostMessageA(hwnd, 0x111, 0x80FE, 0);
}

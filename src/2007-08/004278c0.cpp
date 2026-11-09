// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

extern char G_8bb8e0;
extern char G_8bb8f0;
extern unsigned int G_8bb8f4;

int __stdcall sub_498a50(const char* msg);

int __stdcall sub_4278c0(const char* msg)
{
    int result = sub_498a50(msg);

    if ((G_8bb8f4 & 1) == 0)
    {
        char cl = G_8bb8e0;
        G_8bb8f4 |= 1;
        G_8bb8f0 = cl;
    }

    if (G_8bb8f0 == 0)
    {
        G_8bb8f0 = 1;
        MessageBoxA(0, (const char*)0x789fc0, (const char*)0x78a008, 0);
    }

    return result;
}

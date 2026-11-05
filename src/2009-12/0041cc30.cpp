// from server: 73% by atomic.potato
typedef unsigned long DWORD;
typedef void *HMODULE;
typedef void *FARPROC;

extern "C" DWORD __stdcall GetProcAddress(HMODULE, const char *);
extern "C" DWORD __stdcall UnknownCall(DWORD);

struct CSettingsExplorer
{
    char reserved[0x6c];
    DWORD field6c;
    int f(int *);
};

int CSettingsExplorer::f(int *out)
{
    if (field6c == 0)
        field6c = GetProcAddress((HMODULE)UnknownCall(0x9a3008), "ImageList_DragEnter");
    *out = field6c;
    return 0;
}

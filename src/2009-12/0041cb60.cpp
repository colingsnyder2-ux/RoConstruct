// from server: 71% by atomic.potato
extern "C" int __stdcall GetProcAddress(int, const char*);

struct CSettingsExplorer
{
    int f(int*);
    char padding[0x68];
    int member68;
};

int CSettingsExplorer::f(int* result)
{
    if (member68 == 0)
    {
        int p = 0x009a2ff4;
        member68 = (int)GetProcAddress(0x412f90, (const char*)p);
    }
    *result = member68;
    return 0;
}

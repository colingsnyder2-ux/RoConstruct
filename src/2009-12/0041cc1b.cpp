// from server: 58% by atomic.potato
extern "C" void __cdecl Function007f3b24(int, int);

struct CSettingsExplorer
{
    void f(int edi);
};

void CSettingsExplorer::f(int edi)
{
    if (edi != 2)
        Function007f3b24(0, *(int *)((char *)this - 0x1c));
}

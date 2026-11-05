// from server: 86% by atomic.potato
extern "C" int __stdcall CloseHandle(void*);

void* g_CloseHandle;

struct CSettingsDialog
{
    void f();
    void* a;
    void* b;
};

void CSettingsDialog::f()
{
    if (b != 0 || a != 0)
    {
        CloseHandle(b);
        CloseHandle(a);
        b = 0;
        a = 0;
    }
}

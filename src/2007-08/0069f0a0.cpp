// from server: 100% by colin
// roc 2007-08 0069f0a0  unit: RBX::Kernel  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069f0a0

struct KernelData {
    void* m_field0;
    char pad0[8];
    void* m_fieldC;
};

struct Kernel {
    KernelData* getKernelData();
    int step(int a, int b, int c, int d, int e);
};

extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* lpProcName);

extern void* g_module_handle;
extern char g_proc_name[];

int Kernel::step(int a, int b, int c, int d, int e)
{
    KernelData* kd = getKernelData();
    if (kd->m_fieldC != 0 && kd->m_field0 == 0) {
        kd->m_field0 = GetProcAddress(kd->m_fieldC, g_proc_name);
    }
    void* fn = kd->m_field0;
    if (fn != 0) {
        typedef int (__stdcall *Fn)(int, int, int, int, int);
        return ((Fn)fn)(a, b, c, d, e);
    }
    return (int)0x80004005;
}

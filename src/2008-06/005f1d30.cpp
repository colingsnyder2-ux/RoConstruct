// from server: 100% by tester
extern "C" {
    __declspec(dllimport) void* __stdcall WaitForSingleObject(void*, unsigned long);
    __declspec(dllimport) int __stdcall ReleaseMutex(void*);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
}

extern void* g_77d2b4;
extern void* g_77d1c8;
extern void* g_77d1d4;

struct boost_thread_resource_error {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void f();
};

void boost_thread_resource_error::f()
{
    void* ebx = g_77d2b4;
    void* edi = 0;

    WaitForSingleObject(field8, 0xFFFFFFFF);

    if (field14 != 0) {
        edi = field10;
        if (edi == 0) {
            ReleaseMutex(field8);
            return;
        }
        field14 = (char*)field14 + (int)edi;
        field10 = 0;
    } else {
        WaitForSingleObject(field0, 0xFFFFFFFF);
        void* eax = field10;
        void* ecx = fieldC;
        if (eax > ecx) {
            if (ecx != 0) {
                field10 = (char*)eax - (int)ecx;
                fieldC = edi;
            }
            edi = field10;
            field14 = edi;
            field10 = 0;
        } else {
            ReleaseSemaphore(field0, 1, 0);
        }
    }

    ReleaseMutex(field8);

    if (edi != 0) {
        ReleaseSemaphore(field4, (long)edi, 0);
    }
}

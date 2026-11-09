// from server: 100% by colin
extern "C" {
    __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
    __declspec(dllimport) int __stdcall ReleaseMutex(void*);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
}

struct S {
    void* field0;
    void* field4;
    void* field8;
    int fieldC;
    int field10;
    int field14;
    void method();
};

void S::method()
{
    unsigned long (__stdcall *wait)(void*, unsigned long) = WaitForSingleObject;
    int (__stdcall *relmutex)(void*) = ReleaseMutex;
    int (__stdcall *relsem)(void*, long, long*) = ReleaseSemaphore;

    wait(field4, 0xffffffffUL);
    wait(field8, 0xffffffffUL);

    int edi = field14;
    int ebp = fieldC;

    if (edi != 0) {
        int remaining = edi - 1;
        field14 = remaining;
        if (remaining == 0) {
            if (field10 != 0) {
                relsem(field0, 1, 0);
                edi = 0;
            } else if (ebp != 0) {
                fieldC = 0;
            }
        }
    } else {
        int count = ebp + 1;
        fieldC = count;
        if (count == 0x7fffffff) {
            wait(field0, 0xffffffffUL);
            field10 -= fieldC;
            relsem(field0, 1, 0);
            fieldC = 0;
        }
    }

    relmutex(field8);

    if (edi == 1) {
        while (ebp != 0) {
            wait(field4, 0xffffffffUL);
            --ebp;
        }
        relsem(field0, 1, 0);
    }
}

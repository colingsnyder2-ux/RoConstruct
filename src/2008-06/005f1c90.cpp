// from server: 100% by tester
extern "C" {
    __declspec(dllimport) void* __stdcall WaitForSingleObject(void*, unsigned long);
    __declspec(dllimport) int __stdcall ReleaseMutex(void*);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
}

struct FaceInstance {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void func();
};

void FaceInstance::func()
{
    void* (__stdcall *wait)(void*, unsigned long) = WaitForSingleObject;
    int (__stdcall *release)(void*, long, long*) = ReleaseSemaphore;
    int (__stdcall *relmutex)(void*) = ReleaseMutex;

    int did = 0;
    wait(field8, (unsigned long)-1);

    if (field14 != 0) {
        if (field10 == 0) {
            relmutex(field8);
            return;
        }
        field14 = (char*)field14 + 1;
        field10 = (char*)field10 - 1;
        did = 1;
    } else {
        wait(field0, (unsigned long)-1);
        unsigned int a = (unsigned int)field10;
        unsigned int b = (unsigned int)fieldC;
        if (a > b) {
            if (b != 0) {
                field10 = (void*)(a - b);
                fieldC = (void*)did;
            }
            field10 = (char*)field10 - 1;
            did = 1;
            field14 = (void*)did;
        } else {
            release(field0, 1, 0);
        }
    }

    relmutex(field8);

    if (did != 0) {
        release(field4, did, 0);
    }
}

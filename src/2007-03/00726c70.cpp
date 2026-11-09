// from server: 100% by tester
extern "C" unsigned long (__stdcall *WaitForSingleObject)(void* handle, unsigned long ms);
extern "C" int (__stdcall *CloseHandle)(void* handle);

struct ThreadData {
    void* handle;
    int pad;
    unsigned char flag;
    void destroy();
};

void ThreadData::destroy()
{
    WaitForSingleObject(handle, 0xFFFFFFFF);
    CloseHandle(handle);
    flag = 0;
}

// from server: 100% by king_originala
extern "C" {
    extern unsigned long (__stdcall *WaitForSingleObject)(void*, unsigned long);
    extern int (__stdcall *ReleaseSemaphore)(void*, long, long*);
}

struct S {
    void* handle;
    unsigned char padding[12];
    unsigned long count;
    void f();
};

void S::f()
{
    WaitForSingleObject(handle, 0xFFFFFFFFUL);
    ++count;
    ReleaseSemaphore(handle, 1, 0);
}

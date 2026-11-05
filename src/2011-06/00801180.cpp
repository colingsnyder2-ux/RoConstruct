// from server: 43% by atomic.potato
typedef int BOOL;
typedef void *HANDLE;

extern "C" BOOL __stdcall SetEvent(HANDLE);

struct S
{
    HANDLE handle;
    int f();
};

int S::f()
{
    SetEvent(handle);
    return f();
}

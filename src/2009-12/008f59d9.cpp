// from server: 53% by atomic.potato
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef void* LPVOID;

extern "C" LPVOID __stdcall HeapAlloc(HANDLE, DWORD, DWORD);

struct CXTIconHandle
{
    HANDLE heap;

    LPVOID f(LPVOID size);
};

LPVOID CXTIconHandle::f(LPVOID size)
{
    return HeapAlloc(heap, 0, (DWORD)size);
}

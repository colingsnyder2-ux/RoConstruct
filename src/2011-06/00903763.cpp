// from server: 53% by atomic.potato
typedef unsigned long DWORD;
typedef void* LPVOID;
typedef void* HANDLE;

extern "C" LPVOID __stdcall HeapAlloc(HANDLE, DWORD, DWORD);

struct CXTIconHandle
{
    HANDLE heap;
    LPVOID f(DWORD size);
};

LPVOID CXTIconHandle::f(DWORD size)
{
    return HeapAlloc(heap, 0, size);
}

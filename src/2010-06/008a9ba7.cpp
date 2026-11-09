// from server: 52% by atomic.potato
typedef unsigned long DWORD;
typedef void* HANDLE;

extern "C" DWORD __stdcall HeapSize(HANDLE, DWORD, const void*);

struct CXTIconHandle {
    DWORD Size(const void* p);
};

DWORD CXTIconHandle::Size(const void* p)
{
    return HeapSize(*(HANDLE*)((char*)this + 4), 0, p);
}

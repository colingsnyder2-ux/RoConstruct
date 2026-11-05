// from server: 100% by atomic.potato
typedef void* (__stdcall *FindResourceAFn)(void*, const char*, const char*);
typedef void* (__stdcall *LoadResourceFn)(void*, void*);
typedef void* (__stdcall *LockResourceFn)(void*);
typedef int   (__stdcall *FreeResourceFn)(void*);

extern FindResourceAFn FindResourceA;
extern LoadResourceFn  LoadResource;
extern LockResourceFn  LockResource;
extern FreeResourceFn  FreeResource;

int sub_7bd1f0(void* hModule, const char* lpName)
{
    void* hResInfo = FindResourceA(hModule, lpName, (const char*)2);
    if (hResInfo == 0)
        return 0;

    void* hResData = LoadResource(hModule, hResInfo);
    if (hResData == 0)
        return 0;

    unsigned char* p = (unsigned char*)LockResource(hResData);
    if (p == 0)
        return 0;

    int is32bpp = *(unsigned short*)(p + 0xe) == 0x20;

    FreeResource(hResData);
    return is32bpp;
}
